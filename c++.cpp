#include <iostream>
#include <cstdlib>
#include <ctime>

 using namespace std;

 
int
main ()
{
  
int Random;
  
srand (time (0));
  
Random = rand () % 30;
  
int Try = 5;
  
int Lower = 0, Upper = 30;
  
 
cout <<
	"You have only 5 chances to guess the number.\nIf you can't guess it within 5 tries, you will lose."
	<< endl;
  
 
for (int i = 1; i <= Try; i++)
	{
	  
cout <<
		"============================================================================"
		<< endl;
	  
cout << "HINT: Number is between " << Lower << " to " << Upper << "."
		<< endl;
	  
cout << "Try number " << i << ": ";
	  
 
int Guess;
	  
cin >> Guess;
	  
 
if (Guess == Random)
		{

cout<<"(Y)(o)(u)  {W}{O}{N}(!) "<<endl;
return 0;
		
}
	  else if (i == Try)
		{
		  
cout << "Game Over!" << endl;
		  
cout << "Correct answer: " << Random << endl;
		  
return 0;
		
}
	  else
		{
		  
if (Random > Guess)
			
Lower = Guess;
		  
		  else
			
Upper = Guess;
		  
cout << "Try Again!" << endl;
		
}
	  
 
cout <<
		"------------------------------------------------------------------------------"
		<< endl;
	
}
  
 
return 0;

}



