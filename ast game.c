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
int myarray[100][2] = {};
int pixelcount = 0;
int cursorshift = 2;

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
  arduboy.clear();
  //Game code here

      //Gameplay screen
      arduboy.setCursor(0, 0);
      //arduboy.print("Gameplay");
      //Draw the ball
      arduboy.fillCircle(ballx, bally, ballsize, WHITE);

      for(int x = 0; x < 100; x++) {
      			arduboy.fillCircle(myarray[x][0], myarray[x][1], ballsize, WHITE);
      }

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

      if(arduboy.pressed(A_BUTTON)) {
        myarray[pixelcount][0] = ballx;
        myarray[pixelcount][1] = bally;
        pixelcount++;
        justpressed = 1;
      }
      arduboy.print(pixelcount);
      arduboy.print("-");
      arduboy.print(myarray[pixelcount][0]);
      arduboy.print("-");
      arduboy.print(myarray[pixelcount][1]);
  //Check if the button is being held down
  if(arduboy.notPressed(A_BUTTON)) {
    justpressed = 0;
  }
  arduboy.display();
}
