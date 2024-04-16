#include <iostream>
using namespace std;

int space[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; //initialize row and col
int row;
int col;
char token = 'x';
bool gtie=false;
string n1, n2;

void functionone()
{
    cout << "   |      |   " << endl;
    cout << space[0][0] << "  | " << space[0][1] << " " << "   | " << space[0][2] << endl;
    cout << "___|______|___" << endl;
    cout << "   |      |   " << endl;
    cout << space[1][0] << "  | " << space[1][1] << " " << "   | " << space[1][2] << endl;
    cout << "___|______|___" << endl;
    cout << "   |      |   " << endl;
    cout << space[2][0] << "  | " << space[2][1] << " " << "   | " << space[2][2] << endl;
    cout << "   |      |   " << endl;
}

void functiontwo()
{
    int digit;
    if (token == 'x')
    {
        cout << n1 << "Please Enter: ";
        cin >> digit;
    }

    //for player 2
    if (token == '0') {
        cout << n2 << "Please Enter ";
        cin >> digit;
    }

    //check invalid value

    if (digit == 1) {
        row = 0;
        col = 0;
    }

    else if (digit == 2) {
        row = 0;
        col = 1;
    }

    else if (digit == 3) {
        row = 0;
        col = 2;
    }

    else if (digit == 4) {
        row = 1;
        col = 0;
    }

    else if (digit == 5) {
        row = 1;
        col = 1;
    }

    else if (digit == 6) {
        row = 1;
        col = 2;
    }

    else if (digit == 7) {
        row = 2;
        col = 0;
    }

    else if (digit == 8) {
        row = 2;
        col = 1;
    }

    else if (digit == 9) {
        row = 2;
        col = 2;
    }
    else if(digit<1 || digit>9){
        cout << "Invalid !!" << endl;
        return ;
    }


    if (token == 'x' && space[row][col] != 'x' && space[row][col] != '0') {
        space[row][col] = 'x';
        token = '0';

    }
    else if (token == '0' && space[row][col] != 'x' && space[row][col] != '0') {
        space[row][col] = '0';
        token = 'x';
    }
    else {
        cout << "There is no empty spaces " << endl;
        functiontwo();
    }
}


bool functionthree() {
    // Check for winning conditions
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) // for rows and columns
            return true;    
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) { // for diagonals
        return true;
    }

    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') { // if any cell is not yet marked
                return false;
            }
        }
    }
    gtie = true; // All cells are marked but no winner found, so it's a tie
    return false;
}

int main() {
    // cout << "Enter the name of player 1 : " << endl;
    // getline(cin, n1);

    // cout << "Enter the name of player 2 : " << endl;
    // getline(cin, n2);

    while (!functionthree()) {
        functionone();
        functiontwo();
    }

    functionone(); // Display the final board

    if (gtie) {
        cout << "It's a Draw !" << endl;
    } else if (token == 'x') {
        cout << n2 << " Wins!!" << endl;
    } else {
        cout << n1 << " Wins!!" << endl;
    }

    return 0;
}
