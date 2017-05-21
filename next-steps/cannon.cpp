#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

#define PI              3.14159265
#define VELOCITY        200.0
#define GRAVITY         32.2
#define MAX_DISTANCE    1242

int calculateDistance(double degree) {
    double in_angle = degree * PI / 180;
    double time_in_air = (2.0 * VELOCITY * sin(in_angle)) / GRAVITY;
    return round((VELOCITY * cos(in_angle)) * time_in_air);
}

// This displays the introductory script
void startUp() {
    cout << "Welcome to Artillery." << endl;
    cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
    cout << "You have one cannon, which you can shoot at any angle." << endl;
    cout << "You only have 10 cannonballs for this target.." << endl;
    cout << "Let's begin..." << endl << endl;
}

// contains the main loop of each round
int fire() {
    // generate a random number to get the enemy distance
    srand(time(NULL));
    int enemyDistance = rand() % MAX_DISTANCE + 1;
    cout << "The enemy is " << enemyDistance << " feet away!!!" << endl;

    double angle;
    int distance;
    int shots = 0;
    // set up the loop to get the player's input
    do {
        ++shots;
        cout << "What angle? ";
        cin >> angle;

        // calculate whether or not they have hit the enemy
        distance = calculateDistance(angle);
        if (distance < enemyDistance) {
            cout << "You under shot by " << enemyDistance - distance << endl;
        } else if (distance > enemyDistance) {
            cout << "You over shot by " << distance - enemyDistance << endl;
        } else {
            cout << "You hit him!!!" << endl;
            cout << "It took you " << shots << " shots." << endl;
            cout << "You have killed 1 enemy." << endl;
            return 1;
        }
    } while (shots < 10);
    return 0;
}

void test_calculateDistance() {
    assert(calculateDistance(25) == 507 + 445);
    assert(calculateDistance(15) == 507 + 114);
    assert(calculateDistance(10) == 507 - 82);
    assert(calculateDistance(12) == 507 - 2);
    assert(calculateDistance(12.04) == 507);
    cout << "passed test_calculateDistance" << endl;
}

int main() {
    // test_calculateDistance();
    startUp();
    int killed = 0;
    char done;
    do {
        killed = killed + fire();
        cout << "I see another one, care to shoot again? (Y/N) " << endl;
        cin >> done;
    } while (done != 'n');
    cout << "You killed " << killed << " of the enemy." << endl;
}
