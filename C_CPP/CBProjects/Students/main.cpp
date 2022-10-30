#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int students = 999;
    int subjects = 5;
    srand(time(NULL));
    float a[students][subjects+1] =  {0};
    for (int i = 0; i < students; i++) { // random
        for (int j = 0; j < subjects; j++) {
            a[i][j] = (rand()%41) + 60;
        }
    }


    cout << " Number\tChinese\tMath\tHistory\tScience\tEnglish\tAverage\tHighest\t\tLowest\t\tRanking" << endl;

    // calculate averages
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < subjects; j++)
            sum += a[i][j];
        a[i][subjects] = sum / subjects;
        sum = 0;
    }
    for (int i = 0; i < students; i++) {
        cout << " No." << i + 1 << "\t";
        for (int j = 0; j < subjects; j++)
            cout << (int) a[i][j] << "\t"; // score

        string highest = "Chinese";
        int highestScore = a[i][0]; // highest subject
        for (int j = 0; j < subjects; j++) {
            if (a[i][j] > highestScore) {
                switch (j) {
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
        int lowestScore = a[i][0]; // lowest subject
        for (int j = 0; j < subjects; j++) {
            if (a[i][j] < lowestScore) {
                switch (j) {
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
        for (int j = 0; j < students; j++){ // ranking
            if (a[j][subjects] > a[i][subjects])
                ranking += 1;
        }

        cout << a[i][subjects] << "\t";
        cout << highest << "\t\t";
        cout << lowest << "\t\t";
        cout << ranking;
        cout << endl;
    }
    return 0;
}
