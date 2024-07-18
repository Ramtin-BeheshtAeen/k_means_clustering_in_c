#include "raylib.h"


#define MAX_X 20.0
#define MIN_X -20.0

#define MAX_Y 20.0
#define MIN_Y -20.0

// this function get Vector 2 as an sample and return a Vector 2 
Vector2 project_sample_to_screen(Vector2 sample){

	// -20..20 => 0..1
	// In this section we are going to remap sample cordintation to the 0 to 1:
	float legnth_x = MAX_X - MIN_X;
	float legnth_y = MAX_Y - MIN_Y;

        
	float normalized_x = (sample.x - MIN_X) / legnth_x;
	float normalized_y = (sample.y - MIN_Y) / legnth_y;

	/*
	As for CLITERAL, it seems to be a custom keyword or function that is used to create a literal instance of a Vector2 object.
	In many programming languages, you can create an instance of an object using a constructor or a factory method.
	The CLITERAL keyword appears to be a shorthand for creating a new Vector2 object with specific values for .x and .y.
	It’s similar to how you might use new Vector2(x, y) in other languages to create a new vector with those coordinates.
	*/

	//Map the normalized cordinatio to the screen:
	return CLITERAL(Vector2) {
		.x = GetScreenWidth() * normalized_x;
		.y = GetScreenHeight() * normalized_y;
	}

}

int main(void)
{
    InitWindow(800, 600, "K-means");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GetColor(0x181818AA));
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
