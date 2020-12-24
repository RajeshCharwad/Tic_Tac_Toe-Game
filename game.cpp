using namespace std;
#include<iostream>

class Game
{
    public:
    char matrix[9] = {'1','2','3','4','5','6','7','8','9'};
    string player1, player2;
    Game(string name1, string name2)
    {
        player1 = name1;
        player2 = name2;
    }

    void displayMatrix()
    {
        cout<<endl<<"Player 1 "<<player1<<" (X) "<<"Player 2 "<<player2<<" (O) "<<endl;
        
        cout<<"     |     |     \n";
        cout<<"  "<<matrix[0]<<"  |  "<<matrix[1]<<"  |  "<<matrix[2]<<"  \n";

        cout<<"_____|_____|_____\n";
        cout<<"     |     |     \n";

        cout<<"  "<<matrix[3]<<"  |  "<<matrix[4]<<"  |  "<<matrix[5]<<"  \n";

        cout<<"_____|_____|_____\n";
        cout<<"     |     |     \n";

        cout<<"  "<<matrix[6]<<"  |  "<<matrix[7]<<"  |  "<<matrix[8]<<"  \n";

        cout<<"     |     |     \n\n";
    }

    int markMatrix(char mark, int choice, int player)
    {
        if (choice == 1 && matrix[0] == '1')
        {
            matrix[0] = mark;
        }
        else if (choice == 2 && matrix[1] == '2')
        {
            matrix[1] = mark;
        }
        else if (choice == 3 && matrix[2] == '3')
        {
            matrix[2] = mark;
        }
        else if (choice == 4 && matrix[3] == '4')
        {
            matrix[3] = mark;
        }
        else if (choice == 5 && matrix[4] == '5')
        {
            matrix[4] = mark;
        }
        else if (choice == 6 && matrix[5] == '6')
        {
            matrix[5] = mark;
        }
        else if (choice == 7 && matrix[6] == '7')
        {
            matrix[6] = mark;
        }
        else if (choice == 8 && matrix[7] == '8')
        {
            matrix[7] = mark;
        }
        else if (choice == 9 && matrix[8] == '9')
        {
            matrix[8] = mark;
        }
        else
        {
            printf("Invalid move ");

            player--;
        }

        return player;
    }

    int winner()
    {
        int status = 0;

        if (matrix[0] == matrix[1] && matrix[1] == matrix[2])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[3] == matrix[4] && matrix[4] == matrix[5])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[6] == matrix[7] && matrix[7] == matrix[8])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[0] == matrix[3] && matrix[3] == matrix[6])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[1] == matrix[4] && matrix[4] == matrix[7])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[2] == matrix[5] && matrix[5] == matrix[8])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[0] == matrix[4] && matrix[4] == matrix[8])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[2] == matrix[4] && matrix[4] == matrix[6])
        {
            displayMatrix();
            status = 1;
        }
        else if (matrix[0] != '1' && matrix[1] != '2' && matrix[2] != '3' && matrix[3] != '4' && matrix[4] != '5' && matrix[5] != '6' && matrix[6] != '7' && matrix[7] != '8' && matrix[8] != '9')
        {
            displayMatrix();
            status = 0;
        }
        else
        {
            status = -1;
        }

        return status;
    }
};

int main()
{
    string player1,player2;
    int choice = 0, player = 1, status = -1;
    char mark;
    

    cout<<"Welcome to Tic Tac Toe\n\n";
    cout<<"Please enter name of player 1\n";
    cin>>player1;
    cout<<"Please enter name of player 2\n";
    cin>>player2;
    Game gobj(player1,player2);

    while(status != 0)
    {
        gobj.displayMatrix();

        if((player % 2) != 0)
        {
            player = 1;
            cout<<player1<<" enter a number: \n";
            cin>>choice;
        }
        else
        {
            player = 2;
            cout<<player2<<" enter a number: \n";
            cin>>choice;
        }

        if(player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }
           
       
        
        player = gobj.markMatrix(mark,choice,player);

        if((status = gobj.winner()) == 1)
        {
            break;
        }
        else if((status == 0))
        {
            break;
        }

        player++;
    }

    if(status == 1)
    {
        cout<<"Player "<<player<<" won the game"<<endl;
    }
    else
    {
        cout<<"Game draw\n";
    }
    
    return 0;
}