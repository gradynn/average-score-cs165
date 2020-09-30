#include <iostream>

using namespace std;

void getJudgeData(double *x);
void calcScore(double s[5]);
double findLowest(double a[5]);
double findHighest(double b[5]);

int main() {
    // Array to store all judges scores as one set. Makes for easy manipulation of the data set later on in the program.
    double scores[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    
    // For loop executes once for every element in the array calling the getJudgeData function which appends a user-inputted value to that position in the array.
    for (int i = 0; i < 5; i++) {
        getJudgeData(&scores[i]);
    }

    // Double variable equal to the lowest value of the scores array (determined by calling the findLowest function).
    double l = findLowest(scores);

    /* 
        For loop that cycles through the array until it finds the predetermined lowest value. It then "drops" this 
        value by reassigning it to be 0.0 rendering it effectivley meaningless in the calculation of the average.
    */
    for (int i = 0; i< 5; i++) {
        if (scores[i] == l) {
            scores[i] = 0.0;
        }
    }

    /*
        For loop that cycles through the array until it finds the predetermined highest value. It then "drops" this 
        value as well by reassigning it to be 0.0 rendering it meaningless in the calculation of the average.
    */
    double h = findHighest(scores);
    for (int i = 0; i< 5; i++) {
        if (scores[i] == h) {
            scores[i] = 0.0;
        }
    }

    /*
        This ends the program with a call to the calcScore function that calculates an average of all elements in the array.
        It is also responsible for displaying this average.
    */
    calcScore(scores);


}

//Function that takes the reference variable of nth element in the array and assigns it a user inputted value.
void getJudgeData(double *x) {
    static int count = 1;
    double temp;

    cout << "Enter judge " << count << "'s score: ";
    cin >> temp;

    // While loop tasked with verifying the users input before it appends the temporary value to the main array of scores. Checks that the value is between 0.0 and 10.0.
    while (temp < 0.0 || temp > 10.00) {
        cout << "The score must be between 0 and 10..." << endl;
        cout << "Enter judge " << count << "'s score: ";
        cin >> temp;
    }

    // Assigns the value of temp that exists in the scope of the function to the main array permenantly.
    *x = temp;

    count++;
}

// Function that takes the entire array and computes an average of the doubles stored within it. It is also responsible for displaying the average.
void calcScore(double s[5]) {
    double total = 0;

    for (int i = 0; i < 5; i++) {
        total += s[i];
    }
    
    double avg = total / 3;

    cout << endl << "After dropping the lowest and highest scores, the average was " << avg << endl;
}

// Function that parses a provided array and returns the value of the smallest double in the array. 
double findLowest(double scores[5]) {
    double l = scores[0];
    for (int i = 1; i < 5; i++) {
        if (scores[i] < scores[0]) {
            l = scores[i];
        }
    }

    return l;
}

// Function, similar to above, parses a provided array and returns the value of the largest double in the array.
 double findHighest(double scores[5]) {
    double h = scores[0];
    for (int i = 1; i < 5; i++) {
        if (scores[i] > scores[0]) {
            h = scores[i];
        }
    }

    return h;
}
