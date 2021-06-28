#include<iostream>
#include<ctime>
using namespace std;

void PrintIntroduction(int Difficulty){
    // Welcome Message.....
    cout<<"\n\nYou Are A Secret Agent Breaking Into A Level "<<Difficulty;
    cout<<" Secure Server Room..... \nEnter The Correct Code To Continue: \n \n";
}

bool PlayGame(int Difficulty){
    
    // Calling PrintIntroduction Function...
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum And CodeProduct In Terminal
    cout<<"+There Are 3 Numbers In The Code \n";
    cout<<"+The Codes Add-Up To: " << CodeSum << endl;
    cout<<"+The Codes Multiply To: " << CodeProduct  <<endl;

    int GuessA, GuessB, GuessC;
    cin>>GuessA >> GuessB >> GuessC;

    cout<<"\nYou Entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout << "\n\n*** Well Done Agent! You Have Extracted A File! Keep Going! ***";
        Difficulty += 1;
        return true;
    }
    else{
        cout << "\n\n*** You Entered The Wrong Code! Careful Agent! Try Again! ***";
        return false;
    }

}

int main(){

    srand(time(NULL));
    int const MaxDifficulty = 7;
    int LevelDifficulty = 1;
    while (LevelDifficulty <= MaxDifficulty){
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); //Clear Any Error
        cin.ignore(); //Discard The Buffer

        if (bLevelComplete)
        {
            LevelDifficulty += 1;
        }
        
    }
    cout << "\n\n*** Great Work Agent! You Got All The Files! Now Get Out Of There! ***";
    return 0;
}