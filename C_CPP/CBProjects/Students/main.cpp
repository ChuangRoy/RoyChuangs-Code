#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
// #include <conio.h>

using namespace std;

int main()
{
    bool running = 1;
    int students = 30;
    int subjects = 5;
    int temp = 0;
    int ranking_target = 0;
    int last_ranking_target = 0;
    srand(time(NULL));
    float a[students][subjects+2] = {0};
    float b[students][subjects+2] = {0};
    for (int i = 0; i < students; i++) { // random
        b[i][0] = i+1;
        for (int j = 1; j < subjects+1 ; j++) {
            b[i][j] = (rand()%41) + 60;
        }
    }
    bool increase = 0;
    if (system("CLS")) system("clear");
    while (running) {
        bool rank = 1;
        for (int i = 0; i < students; i++)
            for (int j = 0; j < subjects + 2; j++)
                a[i][j] = b[i][j];
        switch (ranking_target) {
            case '1':ranking_target=1;cout << " Sort By:Chinse";break;
            case '2':ranking_target=2;cout << " Sort By:Math";break;
            case '3':ranking_target=3;cout << " Sort By:History";break;
            case '4':ranking_target=4;cout << " Sort By:Science";break;
            case '5':ranking_target=5;cout << " Sort By:English";break;
            case '6':ranking_target=6;cout << " Sort By:Average";break;
            default:ranking_target=0;cout << " Sort By:Number";rank=0;
        }
        if (last_ranking_target == ranking_target) {
            if (increase)
                increase = 0;
            else
                increase = 1;
        }
        cout << "(1:Chinese|2:Math|3:History|4:Science \n\t\t5:English|6:Average|Other:Number|Same key twice:toggle increase or decrease|ctrl + c:quit)" << endl;
        cout << " Number";
        if (rank)
            cout << "\tRanking";
        cout << "\tChinese\tMath\tHistory\tScience\tEnglish\tAverage";
        cout << "\tHighest\t\tLowest" << endl;

        // calculate averages
        for (int i = 0; i < students; i++) {
            int sum = 0;
            for (int j = 1; j < subjects+1; j++)
                sum += a[i][j];
            a[i][subjects+1] = sum / subjects;
            sum = 0;
        }

        // sort Students
        if (increase) {
            for(int last_index = 0; last_index < students - 1; last_index++) { //sort
                for (int target_index = last_index + 1; target_index > 0; target_index--) {
                    if (a[target_index][ranking_target] > a[target_index-1][ranking_target]) {
                        for (int i = 0; i < subjects + 2; i++) {
                            temp = a[target_index-1][i];
                            a[target_index-1][i] = a[target_index][i];
                            a[target_index][i] = temp;
                        }
                    }
                }
            }
        }
        else {
            for(int last_index = 0; last_index < students - 1; last_index++) { //sort
                for (int target_index = last_index + 1; target_index > 0; target_index--) {
                    if (a[target_index][ranking_target] < a[target_index-1][ranking_target]) {
                        for (int i = 0; i < subjects + 2; i++) {
                            temp = a[target_index-1][i];
                            a[target_index-1][i] = a[target_index][i];
                            a[target_index][i] = temp;
                        }
                    }
                }
            }
        }



        for (int i = 0; i < students; i++) {
            cout << " No." << a[i][0] << "\t";

            string highest = "Chinese";
            int highestScore = a[i][1]; // highest subject
            for (int j = 1; j < subjects+1; j++) {
                if (a[i][j] > highestScore) {
                    switch (j-1) {
                        case 0:highest = "Chinese";break;
                        case 1:highest = "Math";break;
                        case 2:highest = "History";break;
                        case 3:highest = "Science";break;
                        case 4:highest = "English";break;
                        default:cout << "???" << endl;break;
                    }
                    highestScore = a[i][j];
                }
            }
            string lowest = "Chinese";
            int lowestScore = a[i][1]; // lowest subject
            for (int j = 1; j < subjects+1; j++) {
                if (a[i][j] < lowestScore) {
                    switch (j-1) {
                        case 0:lowest = "Chinese";break;
                        case 1:lowest = "Math";break;
                        case 2:lowest = "History";break;
                        case 3:lowest = "Science";break;
                        case 4:lowest = "English";break;
                        default:cout << "???" << endl;break;
                    }
                    lowestScore = a[i][j];
                }
            }
            int ranking = 1;
            if (rank) {
                for (int j = 0; j < students; j++){ // ranking
                    if (a[j][ranking_target] > a[i][ranking_target])
                        ranking += 1;
                }
            }
            
            if (rank)
                cout << ranking << "\t";
            for (int j = 1; j < subjects+1; j++)
                cout << (int) a[i][j] << "\t"; // score
            cout << a[i][subjects] << "\t";
            cout << highest << "\t\t";
            cout << lowest << "\t\t";
            cout << endl;
        }
        fflush(stdin);
        cout << fflush << "\b";
        last_ranking_target = ranking_target;
        // ranking_target = getch();
        cin >> ranking_target;
        if (system("CLS")) system("clear");
    }
    return 0;
}
