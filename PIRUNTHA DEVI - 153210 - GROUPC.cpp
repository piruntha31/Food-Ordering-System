//This program demonstrates a food ordering system
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

//function prototypes
void selectUser(string [],double [],int,int);
int RestMng();
void showMenuMng(string [],double [],int,int);
void updateMenu(string[],double[],int,int);
void addMenu(string [],double [],int,int);
void user(string &);
bool passwordCheck(string);
void showMenuCustomer(string[],double[],int,int);
void makeOrder(string[],double[],int,int,string &);
bool isAlpha(string);
double calcTotalPayPerOrder(double , string &);
double calcEstTime(string [], int, string [], double [],int);
void calcTotalSalesADay(string &, double);
void outputFile1(string &, double &);
void outputFile2(double &);
void outputFile3(string [], double [], int);

//main function
int main()
{
	//declaration of variables
	const int SIZE=15; //initialize size of array
	string food[SIZE] = ""; //initialize content in size of array
	double price[SIZE] = {0.0};//initialize content in sizeofarray
	string name = " "; //initialize content in size of array
	
	int count;//to check num of data
	int i=0;//initialize int i
	
	//read data from text file
	ifstream inFile;
	string filename; 
	string temp = ""; //to replace the enter cin
    
	//process to read data from text file into array
	while(true) //while  the file is exist
	{ 
		cout<<"\t\t\t\tEnter text filename: " <<endl;
		cin >> filename; //ask user text file
		inFile.open(filename.c_str()); //open text file 
		
		if(inFile) //if infile is true
		{ 
			while(!inFile.eof()) //while infile not eof yet
			{ 
			    getline (inFile, food[i],'\t'); //read data from text file
			    food[i] = temp + food[i]; //to avoid the enter space, swap (name) to temp then swap back
			    inFile >> price[i];  //read data from text file
			
			    i++; // increament num of data
			    count=i; //initialize to variable to pass later
			    inFile >> temp; //enter space key in
		
		    }//cout<<"\t\t\t\t after array " <<endl;
			inFile.close();//close the file
			break;
			
		}	
		else 
		{
			cout<<"Error opening file"<<endl;	//if the text file not found
			inFile.clear(); //clear earlier entry
			continue;
		}
	}
	//displaying data in the text file
	cout << "LIST OF MENU" << endl;
	cout << "ITEM " << "\t\t" <<"PRICE (RM) "<< endl;
	for(int m = 0; m < count; m++)
	{
		cout << food[m] << "\t\t" << price[m] << endl;
	}
	
	//call selectUser function 
	selectUser(food, price, SIZE, count);
	return 0;
}

//function header for selectUser
void selectUser(string food[], double price[], int SIZE, int count)
{
	//decaration of variables
	int choice;
	double sales = 0.0,TotalPayments = 0.0;
	string name=" ";
	double total;
	
	cout << "\n\t  |WELCOME TO DEVI'S KITCHEN|\t\n\n" << endl;
	
	cout << "||||||||||||||||||||||||" <<endl;
	cout << "1) RESTAURANT MANAGER " << endl;
	cout << "2) CUSTOMER "           << endl;
	cout << "||||||||||||||||||||||||" << endl;
	cout << "Select a choice : ";
	cin >> choice;//user input choice
	if(choice < 1 || choice > 2)// if expression true following statement executed 
	{
		cout << "Your choice must be (1-2)" << endl;
		cout << "What is your choice: ";
		cin >> choice;//user input again choice
	}
	
	//Declaration of variables
	//control structures for two users 
	//call function referring to each users(Manager and Customer)
	switch(choice)
	{
		case 1:
			int choiceMng;
	    	choiceMng = RestMng();//call RestMng function
	    	switch(choiceMng)
	    	{

                case 1:
		    	updateMenu(food,price,SIZE,count);//call updateMenu function
		    	break;
		    	
		    	case 2:
		    	addMenu(food,price,SIZE,count);//call addMenu function
		    	break;
		    	
		    	case 3:
		    	outputFile1(name,TotalPayments);//call outputFile1 function
		    	break;
		    	
		    	case 4:
		    	outputFile2(sales);//call outputFile2 function
		    	break;
		    	
		    }
		break;
		
		case 2:
		cout << "Hi Mr/Ms ! Please login first before making an order." << endl;
		user(name);//call user function
		showMenuCustomer(food,price,SIZE,count);//call showMenuCustomer function
		makeOrder(food,price,SIZE,count, name);//call makeOrder function
		break;
	}
}

//function header for RestMng 
int RestMng()
{   
    //declaration of variable
    int choiceMng;
	cout << "|||||||||||||||||||||||||||||" <<endl;
	cout << "1) UPDATE MENU " << endl;
	cout << "2) ADD MENU " << endl;
	cout << "3) TOTAL PAYMENT PER ORDER " <<endl;
	cout << "4) TOTAL SALES FOR A DAY " << endl;
	cout << "|||||||||||||||||||||||||||||" << endl;

    cout << "Select a choice : ";
	cin >> choiceMng; //user input choiceMng
	if(choiceMng < 1 || choiceMng > 4) //if expression true following statement executed
	{
		cout << "Your choice must be (1-4)" << endl;
		cout << "What is your choice: ";
		cin >> choiceMng; //user input again choiceMng
	}
	return choiceMng; //return choiceMng to selectUser function
}	

//function header for showMenuMng
void showMenuMng(string food[],double price[],int SIZE,int count)
{
	//declaration of variable
	int idNum = 0;
	
	//manager verification 
	cout << " You're Manager, Please enter ur id number to verify" << endl;
	cin>> idNum; //manager input idNum
	while (!(idNum == 1234)) //while idNum not equals to 1234 following statement executed
	{
		cout << "Wrong ID number, please re-enter correct ID number to verify" << endl;
		cin >> idNum; //manager input idNum and evaluated again
	}
	//to display input file into shoWMenuMng
	cout << "\t=========================\t" << endl;
    cout << "\t        FOOD MENU         " << endl;
    cout << "\t=========================\t" << endl;
    
	for(int j = 0; j < count; j++) //loop control to display food and name
	{   
		cout << "\t" << food[j] << "--------RM " << setprecision(2) << fixed << price[j] << endl;
	}
	
}

//function header for updateMenu
void updateMenu(string food[],double price[],int SIZE,int count)
{
	
	system("cls");
	cout << count;
	//Declaration of data
	int num = 0;
	string choice2,choice3;
	string newFoodname, choice1Food = " ";
	double newPrice;
	
	cout <<"Here is the list"<< endl;
	
	for(int c = 0; c < count; c++) //loop control for food and price in array
	{
		cout << num << ") " << food[c] << "-----RM " << setprecision(2) << fixed << price[c] << endl;
		num++; //increment of number
	}
	
	while(!(choice2 == "N")) //while choice2 not equals to N following statement executed
	{
		cout << "Which one do you want to change? " << endl;
		cin >> choice1Food;//user input choiceFood1
	
		for(int i = 0; i < count; i++) //loop control for food based on choosen food
		{
			if(choice1Food == food[i]) //if this expression true the following statement executed
			{ 
				cout << "You change to : ";
				cin.ignore();
				getline(cin, newFoodname); //user input newFoodname
				food[i] = newFoodname;
			    
				cout << food[i] << "------RM " << setprecision(2) << fixed << price[i] << endl;
				cout << "Will the price be the same ? [Y/N] : ";
				cin >> choice3; //user input choice3
				if(choice3 == "N") //if this expression true the following statement executed
			    {
					cout << "What is new price ? : RM ";
			    	cin >> newPrice; //user input newPrice
			    	price[i] = newPrice;
			    	cout << food[i] << "------RM " << setprecision(2) << fixed << price[i] << endl;
				}
				else
				{
					break;
				}
			}
		
		}
		for (int a = 0; a < count; a++) //loop control for food in array
		{
			if (choice1Food != food[a]) //if the expression true following statement executed
			{
				cout << " The food does not in the list or wrong spelling." << endl;
			break;   //ignore above message if suddenly appears in the output screen as in final the data 
			}	     //user input will be updated in the outputfile and also in the next process
			
		}
	    cout << "Would you like to change the food menu ? [Y/N] : " ;
	    cin >> choice2; //user input choice and evaluated again
	}
	//passing to outputFile3
	outputFile3(food,  price,  count);
    system ("pause");
    system ("cls");		
    selectUser(food, price, SIZE, count);//call function selectUser
    //user need to input the food in the list only in order to get expected output
}

//function header for addMenu
void addMenu(string food[],double price[],int SIZE,int count)
{
	cout << count;
	//declaration of variables
	char choice3;
	int j = count;
	
	showMenuMng(food,price,SIZE,count);
	cout << "Here is the list" << endl;
	
	while(choice3 != 'N') //if true following statement executed
	{
		cout << "Food : ";
		cin.ignore();
		getline(cin,food[j]); //user input food to be added to menu
		
		cout << "Price (RM) : ";
		cin >> price[j]; //user input price to be added to menu 
		
	
	    j++; //increment for j
	    count = j;
	    cout << "Do you want to add anything else ? [Y/N] : ";
	    cin >> choice3; //user input choice3
    }
    outputFile3(food,  price,  count); //call function outputFile3
    selectUser(food, price, SIZE, count); //call function selectUser
}

//function header for user
void user(string &name)
{
    //declaration of variable
	string password;

	cout << "Name : ";
	cin.ignore();
	getline(cin,name);//user input name
	cout << "Password :";
	cin >> password;//user input password
	while(!passwordCheck(password)) // validate the user input password
	{
		cout << "\n\tPassword is Invalid, please reenter/6 digits only ";
		cout << "\n\tRetype Password: ";
		cin.clear();
		cin>> password;//user input password evaluated again
 	}
	cout << "Password is valid!" << endl;
	cout << "You have successfully login!" << endl;
	cout << "You can make orders now!" << endl;
}

//validation function for passwordCheck
bool passwordCheck(string password)
{
	for(int i=0; i<password.length(); i++) //test for numeric digits
	{
		if (isdigit(password[i]) == false)
		{
		    return false; //return status false
		}
	}
	if (password.size() != 6) //test for size of password
	{
		return false; //return status false
	}
    return true; //return status true
}

//function header for showMenuCustomer
void showMenuCustomer(string food[],double price[],int SIZE,int count)
{
	//declaration of variable
	int num = 0;
	cout << "\t=========================\t" << endl;
    cout << "\t        FOOD MENU         " << endl;
    cout << "\t=========================\t" << endl;
    
	for(int j = 0; j < count; j++)//loop control to display food menu 
	{   
		cout << num << ") " << food[j] << "--------RM " << setprecision(2) << fixed << price[j] << endl;
		num++;//increment the number
	}

}	

//function header for makeOrder
void makeOrder(string food[],double price[],int SIZE,int count,string &name)
{
	//declaration of variables
	char choice1;
	string choiceFood = " ";
	int foodQty, ac = 0;
	double total = 0.0, totalP = 0.0, estT = 0.0;
	double Cash = 0.0, balance = 0.0;
	double newPrice = 0.0;
	string foodName;
	string aChoice[15] = {" "};
	int acCount = 0;
	
	while(choice1 != 'N') //while choice1 not equals to N following expression executed
	{
		cout << "What is your choice : ";
		cin.ignore();
		getline(cin, choiceFood); //user input choiceFood
		while (!isAlpha(choiceFood)) //test for alphabatic 
	    {
		    cout << "\n\t\t\tOnly letters are valid";
		    cout << "\n\t\t\tRetype your choiceFood : ";
		    getline(cin, choiceFood); //user input choiceFood and evaluated again
	    }
		
		
		cout << "Checking choices  " << endl;
		aChoice[ac] = choiceFood;
		cout << aChoice[ac] << endl; //display the choosen food
	
        cout << "Quantity: ";
        cin >> foodQty; //user input foodQty

        acCount = ac;
    
        	for(int a = 0; a < count; a++) //loop control to display food and price
        	{
        	
			    if(aChoice[a] == food[a]) //if choosen choiceFood equals to food in array  
			    { 
			        cout << food[a] << "--RM" << price[a] << endl; //display the food and price
	        	    cout << "Food as above" << endl;
	    	        newPrice = foodQty * price[a]; // calculation for newPrice 
	    	        cout << "newPrice : RM " << newPrice << endl; //display totalP
	    	        total += newPrice; // add the newPrice to total and the value is assigned to total
	    	    	cout << "Total : RM " << total << endl; //display totalP
				}
	    	    else if (choiceFood != food[a])
				{
					cout << " The food does not in the list or wrong spelling." << endl;
				    //ignore this message if appear as there is some problem in this loop
				}   //hv been tried many times but still this problem occuring
	    	}	
		
        
    cout << "Total menu : RM " << total << endl; //display totalP
    
	cout << "Would u like to order anything else ? [Y/N]: ";
	cin >> choice1;
	ac++;
	acCount = ac;
    }
    
    totalP = calcTotalPayPerOrder(total, name); //call function calcTotalPayPerOrder
    
	cout << "Total payment : RM " << totalP << endl; //display totalP
	cout << "Cash : RM ";
    cin >> Cash; //user input cash
    while(Cash < totalP) //if expression true following statement executed
	{
    	cout << "Sorry Ms/Mr, your total amount is bigger than your cash, please re-enter the amount you would like to pay" << endl;
		cout << "Cash : RM ";
		cin >> Cash; //user input cash and evaluated again
	}
	balance = Cash - totalP; //calculation for balance
	if (balance < 1) //if expression true following statement executed
	{
		cout << "  No change " << endl;//display no change
	}
	else//else following statement executed
	{
		cout << "Change : RM " << balance <<"\n\n";// display the balance
	}
	
    estT = calcEstTime(aChoice, acCount, food, price,count);//call function calcEstTime
    cout << "Your food will be delivered in " << estT << " minutes" << endl;
    cout << "THANK YOU! HAVE A NICE MEAL!" << endl;
cout << "Redirecting to main" << endl;
selectUser(food, price, SIZE, count);    //call function selectUser
//there is problem in this function hv been tried many times the problem still occuring but the values are passed correctly
}

//validation function for letters
bool isAlpha(string choiceFood)
{
	for(int i = 0; i < choiceFood.length(); i++)
	{
		if ((isalpha(choiceFood[i]) || choiceFood[i] == ' ') == false)  
		{
			return false; //return status false 
		}	
	}
return true; //return status true
}

//function header for calcTotalPayPerOrder
double calcTotalPayPerOrder(double total, string &name)
{   
    //declaration of variables
	double charge,TotalPayments;
	int idNum = 0;
	
    //manager verification
	cout << " You're Manager, please enter your ID number to verify" << endl;
	cin>> idNum; //manager input idNum
	while (!(idNum == 1234)) //if expression true,following statement executed
	{
		cout << "Wrong ID number, please re-enter correct ID number to verify" << endl;
		cin >> idNum; //manager input again idNum and evaluted again
	}
	cout << "Current price : RM  " << total<< endl; //display total price passed from makeOrder function
	cout << " Delivery charge : RM ";
	cin >> charge; //manager input delivery charge
	
	TotalPayments = total + charge; //total price added with charge
    calcTotalSalesADay(name, TotalPayments); //call function calcTotalSalesADay
	
	return TotalPayments; 	//return the value of TotalPayments
}

//function header for calcEstTime
double calcEstTime(string aChoice[], int acCount, string food[], double price[],int count)
{
	//declaration of variables
	int ac = 0;
	double es, te= 0.0;
	
	for(int i = 0; i < acCount; i++) //loop control for choosen food   
	{
		for(int a = 0; a < count; a++) //loop control for food and price in array
		{
			if(aChoice[i] == food[a] && price[a] > 10) //if expression true following statement executed
			{
				es = 10;
				
		 	}
		 	else if(aChoice[i] == food[a] && price[a] < 10) // else if expression true following statement executed
		 	{
		 		es = 4.05;
			
			}
		}
	te += es; // adds esttime to totalesttime and the result is assigned to totalesttime
	}
	
	cout << "Overall EstTime : " << te << " minutes" << endl;
	return te; //return totalesttime to function makeOrder
}

//function header for calcTotalSalesADay
void calcTotalSalesADay(string &name, double TotalPayments)
{   
    //declaration of variable
	double sales = 0.0;
	sales += TotalPayments;	// add TotalPayment to sales and the value is assigned to sales
	
	outputFile2(sales);

}

//function header for outputFile1
void outputFile1(string &name,double &TotalPayments)
{
	int count;
	ofstream outputFile1;
	//open file
	
	outputFile1.open("totalPayPerOrder.txt",ios_base::app);
	if(outputFile1) //if true following statement executed
	{
		cout << "Tranfering data..." << endl;
		//read the data
		outputFile1 << "\t TOTAL PAYMENT PER ORDER \t" << endl;
		outputFile1 << name << "\t\t" << "RM " << TotalPayments << endl; //display the name and TotalPayments
	}
	else // else following statement executed
	{
		cout << "No data transferred" << endl;
	}
    outputFile1.close();
	system("pause");
	//close the file
}

//function header for outputFile2
void outputFile2(double &sales)
{
	ofstream outputFile2;
	//open file

	outputFile2.open("totalSalesADay.txt",ios_base::out);
	if(outputFile2) //if true following statement executed
	{
		cout << "Transfering data..." << endl;
		//read data
		cout << "\t TOTAL SALES A DAY \t" << endl;
		outputFile2 << "RM " << sales << endl;
	}
	else // else following statement executed
	{
		cout << "No data transferred" << endl;
	}
	outputFile2.close();
	system("pause");
	//close the file
}

//function header for outputFile3
void outputFile3(string food[], double price[], int count)
{
	ofstream outputFile3;
	//open file
	
	outputFile3.open("UpdatedMenu.txt",ios_base::out);
	if(outputFile3) //if true following statement executed
	{
		for(int a=0; a<count; a++ )
		{
			outputFile3 << food[a] << "\t" << price[a] << endl;
		}
	}
	else // else following statement executed
	{
		cout << "No data transferred" << endl;
	}
	outputFile3.close();
	system("pause");
	//close file
}


