#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int startingoption=0, playerchoice;
	char thisposition;
	int gameturn=0;
	bool endgame = false, alloccupied=false;
	bool occupied1 = false, occupied2 = false, occupied3 = false, occupied4 = false, occupied5 = false, occupied6 = false, occupied7 = false, occupied8 = false, occupied9 = false;
	char thisplayer = 'X';
	char num1='1', num2='2', num3='3', num4='4', num5='5', num6='6', num7='7', num8='8', num9='9';
	cout<<endl<<endl<<setw(50)<<"Multiplayer (Player vs Player)\n\n\n";
	cout<<setw(35)<<"Main Menu";
	cout<<"\n\n\t   Select:\n\n";
	cout<<"\t\t  Press (1) for 'HOW TO PLAY'\n\t\t  Press (2) for 'START THE GAME'"<<endl;
	
	
	
	while(startingoption != 1 || startingoption!= 2)
	{
		cin>>startingoption;
			
	if(startingoption!=1 && startingoption!=2)
	{
		cout<<"\t\tIncorrect option!\n\t\tChoose again: ";
		cin>>startingoption;
	}
	
	else if(startingoption == 1)
	{
		cout<<"\t\t1. The game is played on a grid that is 3 squares by 3 squares.\n\t\t2. You are X and your friend is O or vice versa. Players take turns choosing their option in empty squares.\n\t\t3. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n\t\t4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.";
		cout<<endl;
		cout<<"\n\t\tPress (2) to 'START THE GAME'"<<endl;
	}
	
	else if(startingoption == 2)
	{
		cout<<"\tChoose your player:\n\n\t\t(1) for PLAYER 1: [X]\n\t\t(2) for PLAYER 2: [O]"<<endl;
		cin>>playerchoice;
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		if(playerchoice == 1) // First player 1 (X) will start
		{	
			while(endgame != true)
			{
								
				
				while(alloccupied!=true)
				{
					cout<<"\t\tCurrent Turn: "<<"["<<thisplayer<<"]"<<endl<<endl;
				cout<<"\t\tChoose your position to place symbol!"<<endl<<endl<<endl;
				
				cout<<"\t\t     |     |     "<<endl;
				cout<<"\t\t  "<<num1<<"  |  "<<num2<<"  |  "<<num3<<"  "<<endl;
				cout<<"\t\t_____|_____|_____"<<endl;
				cout<<"\t\t     |     |     "<<endl;
				cout<<"\t\t  "<<num4<<"  |  "<<num5<<"  |  "<<num6<<"  "<<endl;
				cout<<"\t\t_____|_____|_____"<<endl;
				cout<<"\t\t     |     |"<<endl;
				cout<<"\t\t  "<<num7<<"  |  "<<num8<<"  |  "<<num9<<"  "<<endl;
				cout<<"\t\t     |     |"<<endl;
				

					cin>>thisposition;
					
				switch(thisposition)
				{
					case '1':
					if(occupied1 == false)
					{
						num1 = thisplayer;
						gameturn++;
						occupied1 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '2':
						if(occupied2 == false)
					{
						num2 = thisplayer;
						gameturn++;
						occupied2 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '3':
						if(occupied3 == false)
					{
						num3 = thisplayer;
						gameturn++;
						occupied3 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '4':
					if(occupied4 == false)
					{
						num4 = thisplayer;
						gameturn++;
						occupied4 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '5':
						if(occupied5 == false)
					{
						num5 = thisplayer;
						gameturn++;
						occupied5 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '6':
						if(occupied6 == false)
					{
						num6 = thisplayer;
						gameturn++;
						occupied6 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '7':
						if(occupied7 == false)
					{
						num7 = thisplayer;
						gameturn++;
						occupied7 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '8':
						if(occupied8 == false)
					{
						num8 = thisplayer;
						gameturn++;
						occupied8 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '9':
						if(occupied9 == false)
					{
						num9 = thisplayer;
						gameturn++;
						occupied9 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					default : 
							cout<<"Wrong Input Choose again!";
							break;
				}
				
				if(gameturn==9)
					{
						thisplayer = 'X';
						alloccupied = true;
					}
				
				}
			
			if((num1 == num2 && num1 == num3) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num4 && num1 == num7) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num5 && num1 == num9) || (num3 == num5 && num3 == num7))
				{
					endgame = true;
					cout<<"Congratulations! "<<thisplayer<<" Wins!";
					break;
				}
			else if(gameturn == 9 && ( (num1 == num2 && num1 == num3) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num4 && num1 == num7) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num5 && num1 == num9) || (num3 == num5 && num3 == num7)))
				{
					endgame = true;
					cout<<"Congratulations! "<<thisplayer<<" Wins!";
					break;
				}
			
			else if(gameturn == 9 && !(((num1 == num2 && num1 == num3) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num4 && num1 == num7) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num5 && num1 == num9) || (num3 == num5 && num3 == num7))))			
				{
					endgame = true;
					cout<<"The game is a draw!";
					break;
				}
			}
			
		}
		
		else if(playerchoice == 2) // First player 2 (O) will start
		{
			thisplayer = 'O';
			
			while(endgame != true)
			{
								
				
				while(alloccupied!=true)
				{
					cout<<"\t\tCurrent Turn: "<<"["<<thisplayer<<"]"<<endl<<endl;
				cout<<"\t\tChoose your position to place symbol!"<<endl<<endl<<endl;
				
				cout<<"\t\t     |     |     "<<endl;
				cout<<"\t\t  "<<num1<<"  |  "<<num2<<"  |  "<<num3<<"  "<<endl;
				cout<<"\t\t_____|_____|_____"<<endl;
				cout<<"\t\t     |     |     "<<endl;
				cout<<"\t\t  "<<num4<<"  |  "<<num5<<"  |  "<<num6<<"  "<<endl;
				cout<<"\t\t_____|_____|_____"<<endl;
				cout<<"\t\t     |     |"<<endl;
				cout<<"\t\t  "<<num7<<"  |  "<<num8<<"  |  "<<num9<<"  "<<endl;
				cout<<"\t\t     |     |"<<endl;
				

					cin>>thisposition;
					
				switch(thisposition)
				{
					case '1':
					if(occupied1 == false)
					{
						num1 = thisplayer;
						gameturn++;
						occupied1 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '2':
						if(occupied2 == false)
					{
						num2 = thisplayer;
						gameturn++;
						occupied2 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '3':
						if(occupied3 == false)
					{
						num3 = thisplayer;
						gameturn++;
						occupied3 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '4':
					if(occupied4 == false)
					{
						num4 = thisplayer;
						gameturn++;
						occupied4 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '5':
						if(occupied5 == false)
					{
						num5 = thisplayer;
						gameturn++;
						occupied5 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '6':
						if(occupied6 == false)
					{
						num6 = thisplayer;
						gameturn++;
						occupied6 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '7':
						if(occupied7 == false)
					{
						num7 = thisplayer;
						gameturn++;
						occupied7 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '8':
						if(occupied8 == false)
					{
						num8 = thisplayer;
						gameturn++;
						occupied8 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					case '9':
						if(occupied9 == false)
					{
						num9 = thisplayer;
						gameturn++;
						occupied9 = true;
					}
					else
					{
						cout<<"\n\t\tAlready occupied, choose another option!"<<endl<<endl;
					}
						if(thisplayer == 'X')
						{
							thisplayer = 'O';
						}	
						else if(thisplayer == 'O')
						{
							thisplayer = 'X';
						}
						break;
					default : 
							cout<<"Wrong Input Choose again!";
							break;
				}
				
				if(gameturn==9)
				{
					thisplayer = 'O';
					alloccupied = true;
				}
				}
			if((num1 == num2 && num1 == num3) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num4 && num1 == num7) || (num2 == num5 && num2 == num8) || (num3 == num6 && num3 == num9) || (num1 == num5 && num1 == num9) || (num3 == num5 && num3 == num7))
				{
					endgame = true;
					cout<<"Congratulations! "<<thisplayer<<" Wins!";
					break;
				}
			if(gameturn == 9 && ( (num1 == num2 && num1 == num3) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num4 && num1 == num7) || (num2 == num5 && num2 == num8) || (num3 == num6 && num3 == num9) || (num1 == num5 && num1 == num9) || (num3 == num5 && num3 == num7)))
				{
					endgame = true;
					cout<<"Congratulations! "<<thisplayer<<" Wins!";
					break;
				}
			
			else if(gameturn == 9 && !( (num1 == num2 && num1 == num3) || (num4 == num5 && num4 == num6) || (num7 == num8 && num7 == num9) || (num1 == num4 && num1 == num7) || (num2 == num5 && num2 == num8) || (num3 == num6 && num3 == num9) || (num1 == num5 && num1 == num9) || (num3 == num5 && num3 == num7)))				
				{
					endgame = true;
					cout<<"The game is a draw!";
					break;
				}
			}	
			}
		}
	}
	
	return 0;	
}
