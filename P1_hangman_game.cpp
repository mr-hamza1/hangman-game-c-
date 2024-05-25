#include<iostream>
#include<string>
#include<time.h>
#include<vector>
using namespace std;
char guess;
string random(vector<string>&words);
vector<string> words={"hamza","hangman","programmer","games"};
int backend();
string game_art[7]={
   " +----+\n"
   " |    |\n"
   "      |\n"
   "      |\n"
   "      |\n"
   "      |\n"
   " ========",
   " +----+\n"
   " |    |\n"
   " O    |\n"
   "      |\n"
   "      |\n"
   "      |\n"
   " ========",
   " +----+\n"
   " |    |\n"
   " O    |\n"
   " |    |\n"
   "      |\n"
   "      |\n"
   " ========",
   " +----+\n"
   " |    |\n"
   " O    |\n"
   "/|    |\n"
   "      |\n"
   "      |\n"
   " ========",
   " +----+\n"
   " |    |\n"
   " O    |\n"
   "/|\\   |\n"
   "      |\n"
   "      |\n"
   " ========",
   " +----+\n"
   " |    |\n"
   " O    |\n"
   "/|\\   |\n"
   "/     |\n"
   "      |\n"
   " ========",
   " +----+\n"
   " |    |\n"
   " O    |\n"
   "/|\\   |\n"
   "/ \\   |\n"
   "      |\n"
   " ========"
   

             
};



int main()
{   system("cls");
    cout<<"\n\n\n\n\n\n\n\n                                                        WELCOME TO HANGMAN GAME :)\n\n\n\n";
    system("pause");
    srand(time(0));
    backend();


    
}
int backend()
{  system("cls");
    string guess_word,secret_word;
    secret_word=random(words);
    guess_word=secret_word;
    int i;
    int tryno=0;
    
    for( i =0;i<=secret_word.length();i++)
    {
       guess_word[i]= '_';
    }
    while(true)
    {
        cout<<game_art[tryno]<<endl;
        cout<<guess_word<<endl;
        cout<<"Enter a guess letter\n";
        cin>>guess;

        if(secret_word.find(guess) != string::npos)
        {
            for( int a=0;a<=guess_word.length();a++)
            {
                if(secret_word[a]==guess)
                {
                    guess_word[a]=guess;
                }
            }
            
             if(secret_word==guess_word)
            {   char playagain;
                cout<<game_art[tryno];
                cout<<endl<<guess_word;
                cout<<"\n You win!\n for play again press (Y) ";
                char again;
                cin>>again;
                if(again=='Y')
                backend();
                else
                break;
            
            }
            
        }
        else
        {
            ++tryno;}

           
            if(tryno>6)
            {
                cout<<game_art[tryno];
                cout<<endl<<"You lost!\nFor play again click on Y/N";
                char playagain2;
                cin>>playagain2;
                if(playagain2=='Y')
                backend();
                else
                break;
                }
    }
}
string random(vector<string>&words)
{
   return words[rand()% words.size()];
}