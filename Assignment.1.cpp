/******************************************************************************

write a function that accepts an input and then searches myArray for this input.
The function should return true if found and false other wise

*******************************************************************************/
#include <iostream>

using namespace std;

bool search(int value, int *myArray, int size) 
{
    //int arrSize = sizeof(myArray)/sizeof(myArray[0]);
    
    for (int i = 0; i < size; i++) {
        if (myArray[i] == value)
            return true;
    }
    return false;
}

int main(void)
{
    int myArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    
    if (search(7, myArray, 10) == true)
        cout << "Found.." << endl;
    else
        cout << "Not found.." << endl;
        
    return 0;
}


//2.write a function that accepts myArray and n as inputs then returns (or prints) 
//the minimum value among the first n elements of myArray.


int minValue(int myArray[], int n) 
{
    int minval = myArray[0];
    for (int i = 0; i < n; i++) {
        if (minval > myArray[i])
            minval = myArray[i];
    }
    return minval;
}

int main(void)
{
    int myArray[] = {2, 4, 6, 8, 10, 12, 1, 16, 18, 20};
    
    int minval = minValue(myArray, 8);

    cout << "Min Value = " << minval << endl;
        
    return 0;
}

/******************************************************************************
3. write a function that returns (or prints) both the maximum and minimum values of 
myArray. use reference parameters.

void getArrayMaxMin(float& min, float& max, float myArray[], int arraySize)
*******************************************************************************/

void getArrayMaxMin(float& min, float& max, float myArray[], int arraySize)
{
    //find min value
    min = myArray[0];
    for (int i = 0; i < arraySize; i++) {
        if (min > myArray[i])
            min = myArray[i];
    }
    
    //find max value
    max = myArray[0];
    for (int i = 0; i < arraySize; i++) {
        if (max < myArray[i])
            max = myArray[i];
    }
}

int main(void)
{
    float myArray[] = {2.3, 4.5, 6.1, 8.7, 10.3, 12.1, 1.5, 16.4, 18.9, 15.};
    float min, max;
    
    getArrayMaxMin(min, max, myArray, 10);
    cout << "Min Value = " << min << endl;
    cout << "Max Value = " << max << endl;
        
    return 0;
}


/******************************************************************************
4. write a function that returns (or prints) both the largest and second largest
values in myArray. use reference parameters. Note: largest and second largest can
equal (e.g. a[5] = {3,1,2,3,2}).

void twoLargest(float& maxOne, float& maxTwo, float myArray[], int arraySize)
*******************************************************************************/
void twoLargest(float& maxOne, float& maxTwo, float myArray[], int arraySize)
{
    float temp[arraySize];
    int maxIndex;
    
    //find min value
    float min = myArray[0];
    for (int i = 0; i < arraySize; i++) {
        if (min > myArray[i])
            min = myArray[i];
    }
    
    //find max value
    maxOne = myArray[0];
    for (int i = 0; i < arraySize; i++) {
        temp[i] = myArray[i];
        if (maxOne < myArray[i]) {
            maxOne = myArray[i];
            maxIndex = i;
        }
    }
    temp[maxIndex] = min;
    
    //find second max value
    maxTwo = temp[0];
    for (int i = 0; i < arraySize; i++) {
        if (maxTwo < temp[i])
            maxTwo = temp[i];
    }
}

int main(void)
{
    float myArray[] = {2.3, 4.5, 6.1, 8.7, 10.3, 12.1, 1.5, 16.4, 18.9, 15.};
    float maxOne, maxTwo;
    
    twoLargest(maxOne, maxTwo, myArray, 10);
      
    cout << "First max value = " << maxOne << endl;
    cout << "Second max value = " << maxTwo << endl;
        
    return 0;
}

/******************************************************************************
5. write a function that returns (or prints) the standard deviation of a data set

note:
verify the results using

https://www.calculatorsoup.com/calculators/statistics/standard-deviation-calculator.php
*******************************************************************************/

#include <cmath>


float stdDev(float myArray[], int arrSize)
{
    float sd = 0.;
    float sum = 0.;
    float avg = 0.;
    float var = 0.;
    
    for (int i = 0; i < arrSize; i++)
        sum = sum + myArray[i];
    
    avg = sum / (float) arrSize;
    
    for (int i = 0; i < arrSize; i++)
        var = var + ( (myArray[i] - avg) * (myArray[i] - avg) );
    var = var / (float) (arrSize-1);
    
    sd = sqrt(var);
    return sd;
}

int main(void)
{
    float myArray[] = {2.3, 4.5, 6.1, 8.7, 10.3, 12.1, 1.5, 16.4, 18.9, 15.2};
    float sd;
    
    sd = stdDev(myArray, 10);
      
    cout << "Standard Deviation = " << sd << endl;
        
    return 0;
}

/******************************************************************************

6. write a function that accepts one line of text as input and prints out
thesame text with upper case characters.

*******************************************************************************/
void upperString(string s)
{
    for (int i = 0; i < s.length(); i++)
        putchar(toupper(s[i]));
}

int main(void)
{
    string myString;
    
    cout << "Enter a line of text: " << endl;
    getline(cin >> ws, myString);
    
    upperString(myString);
        
    return 0;
}

******************************************************************************

//7. write a function that accepts one line of text as input and prints out the 
//text with the words reversed (e.g. input: Thank god its friday; output: friday 
//its god thank)

******************************************************************************

#include <string>
#include <vector>

using namespace std;

void reverseString(string s)
{
    vector<string> sVec;
    string temp = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            temp = temp + s[i];
        else {
            sVec.push_back(temp);
            temp = "";
        }
    }
    sVec.push_back(temp);
    temp = "";
    
    for (int i = sVec.size()-1; i >= 0; i--)
        cout << sVec[i] << " ";
}

int main(void)
{
    string myString;
    
    cout << "Enter a line of text: " << endl;
    getline(cin >> ws, myString);
    
    reverseString(myString);
        
    return 0;
}

/******************************************************************************
8. write a function that reads full names and prints them out in standard telephone
directory format (e.g. input: Martin Luther King; output: King, Martin L.)
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeDirectory(string s)
{
    vector<string> sVec;
    string temp = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            temp = temp + s[i];
        else {
            sVec.push_back(temp);
            temp = "";
        }
    }
    sVec.push_back(temp);
    temp = "";
    
    cout << sVec[2] << ", " << sVec[0] << " " << sVec[1][0] << "." << endl;
}

int main(void)
{
    string myString;
    vector<string> myDirectory;
    
    cout << "Enter your name: " << endl;
    getline(cin >> ws, myString);
    makeDirectory(myString);
    
    return 0;
}

/******************************************************************************
9. write a function that returns the number of lines, words and letter frequency 
in its input.

note: returns number of words, letter frequency
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define A 65
#define Z 90
#define a 97
#define z 122

void textStats(int &numLines, int &numWords, int letterFreq[], string s)
{
    vector<string> sVec;
    string temp = "";

    //word count
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            temp = temp + s[i];
        else {
            sVec.push_back(temp);
            temp = "";
            numWords++;
        }
    }
    sVec.push_back(temp);
    temp = "";
    numWords++;
    
    //letter frequency
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= A && s[i] <= Z)
            (letterFreq[s[i] - A])++;
        if (s[i] >= a && s[i] <= z)
            (letterFreq[s[i] - a + 26])++;
    }
}

int main(void)
{
    string myString;
    int numLines = 0, numWords = 0, letterFreq[52] = {0};
    char ch[52];
    
    cout << "Enter text: " << endl;
    getline(cin >> ws, myString);
    textStats(numLines, numWords, letterFreq, myString);
    
    for (int i = 0; i < 26; i++)
        ch[i] = i + A;
    for (int i = 26; i < 52; i++)
        ch[i] = i + a - 26;
        
    cout << "Number of Words in the text = " << numWords << endl;
    cout << "Letter Frequency:" << endl;
    cout << "-----------------" << endl;
    
    for (int i = 0; i < 52; i++)
        cout << ch[i] << ": " << letterFreq[i] << endl;
    
    return 0;
}
