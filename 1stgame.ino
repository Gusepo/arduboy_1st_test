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
bool cursorArea;

void setup() {
  arduboy.begin();
  //Seed the random number generator
  srand(7/8);
  //Set the game to 60 frames per second
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

      if(arduboy.pressed(UP_BUTTON) and bally > 0) {
        bally = bally - cursorshift;
      }
      if(arduboy.pressed(DOWN_BUTTON) and bally < 62) {
        bally = bally + cursorshift;
      }
      if(arduboy.pressed(LEFT_BUTTON) and ballx > 0) {
        ballx = ballx - cursorshift;
      }
      if(arduboy.pressed(RIGHT_BUTTON) and bally < 126) {
        ballx = ballx + cursorshift;
      }

      cursorArea = arduboy.getPixel(ballx, ballx);

      arduboy.drawPixel(ballx, bally, WHITE);

      if(arduboy.pressed(A_BUTTON)) {
        arduboy.drawPixel(ballx, bally, WHITE);
      } else {
        if (cursorArea==0) {
          arduboy.drawPixel(ballx, ballx, BLACK);
        }
      }

  arduboy.display();
}
