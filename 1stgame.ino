#include <Arduboy.h>
Arduboy arduboy;

//Variables declared here
int gamestate = 0;
int justpressed = 0;
int ballx = 62;
int bally = 30;
int ballsize = 2;
int ballright = 1;
int balldown = 1;
int pixelcount = 0;
int cursorshift = 1;
int ball_prevx = 0;
int ball_prevy = 0;
bool cursorArea = 0;
byte cursorColour;

void setup() {
  arduboy.begin();

  arduboy.setFrameRate(30);
  arduboy.clear();
}

void loop() {
  //Prevent the Arduboy from running too fast
  if(!arduboy.nextFrame()) {
    return;
  }
      //arduboy.clear();
      arduboy.setCursor(0,0);
      ball_prevx = ballx;
      ball_prevy = bally;

      justpressed = 0;
        
      if(arduboy.pressed(UP_BUTTON) && bally > 0) {
        bally = bally - cursorshift;
        justpressed = 1;
      }
      if(arduboy.pressed(DOWN_BUTTON) && bally < 62) {
        bally = bally + cursorshift;
        justpressed = 1;
      }
      if(arduboy.pressed(LEFT_BUTTON) && ballx > 0) {
        ballx = ballx - cursorshift;
        justpressed = 1;
      }
      if(arduboy.pressed(RIGHT_BUTTON) && bally < 126) {
        ballx = ballx + cursorshift;
        justpressed = 1;
      }

      //if in previous position Abutton was clicked paint the pixel white
      if (cursorArea==1) {
        arduboy.drawPixel(ball_prevx, ball_prevy, WHITE);
      }

      //get the color of the pixel before the cursor moves on it
      cursorArea = arduboy.getPixel(ballx, bally);

      if (arduboy.everyXFrames(15)) {
         cursorColour = cursorColour == BLACK ? WHITE : BLACK;
           arduboy.drawPixel(ballx, bally, cursorColour);
       }

      if(arduboy.pressed(A_BUTTON)) {
        cursorArea = 1;
      } 

  arduboy.display();
}
