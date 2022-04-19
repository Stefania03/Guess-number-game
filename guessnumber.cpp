/*********************************
 *     A NUMBER GUESSING GAME    *
 *********************************/

#include<iostream>
#include<cstdlib>  // srand() function 
#include<ctime>    // time() function

using namespace std;

// function to generate a random number that should be guessed
// using rand()
int random_number_generator()
{
	int secret_num;
	secret_num = rand()%100+0;  //selects random number 
	return secret_num;
}

// boolean function to verify compatibility between secret nr and guessed nr
// it returns true if the guess is correct, false if it's not
bool check_match(int secret_num, int guess)
{
	if(secret_num == guess)
		return true;
	return false;
}

// function to give hints if your guess is wrong
// if your guess is bigger than secret number, it returns "too high"
// if your guess is less than secret number, it returns "too low"
void check_range(int secret_num, int guess)
{
		if(guess > secret_num)
			cout << "too high" << endl;
		else if(guess < secret_num) 
			cout << "too low" << endl;
}

int main(void)
{
	int secret_num, guess;

    // seeds the random number generator
	srand(time(NULL));
	
    // make call to the random_number_generator() function
	secret_num = random_number_generator();

	do
	{   
        // input your guess
		cout << "Enter your guess: ";
		cin >> guess;
		
        // verify if guess matches the secret number
		if(check_match(secret_num, guess))
			cout << "Congratulations you guessed correctly" << endl;
		else
		{   
            // give hint if wrong
			check_range(secret_num, guess);
            // sorry message
			cout << "\n" << "Sorry please try again" << endl; 
		}
			
	}
	while(guess != secret_num);

	return 0;
}