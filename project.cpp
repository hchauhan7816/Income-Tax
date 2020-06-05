#include<bits/stdc++.h>
#include<windows.h>
typedef long long int ll;
using namespace std;

// Creating a Person's class which defines each person as an unique entity.
class person{
	
	private:
		//Person's Details are private for the person's security
		string address , name , job;
		ll id;

	public:
		//Creating Getters and Setters
		//Taking and processing Address as (address)
		string getAddress(){
			return address;
		}
		void setAddress(string addressInput){
			address = addressInput;
		}

		//Taking and processing Name as (name)
		string getName(){
			return name;
		}
		void setName(string nameInput){
			name = nameInput;
		}

		//Taking and processing Profession as (job)
		string getJob(){
			return job;
		}
		void setJob(string jobInput){
			job = jobInput;
		}

		//Taking and processing Adhar Card ID as (id);
		ll getId(){
			return id;
		}
		void setId(ll IdInput){
			id = IdInput;
		}

		//Taking the data of a person and storing respectively
		void getPerson(){

			// first -> name , second -> address , third -> id 
			string first , second;
			ll third;
			cout << "\tEnter your name\t\t\t:: " ;
			cin >> first;
			cout << "\tEnter your address\t\t:: " ;
			cin >> second;
			cout << "\tEnter your Adhar Card Number\t:: ";
			cin >> third;
			cout << endl;

			// setting values
			setName(first);
			setAddress(second);
			setId(third);
		}

		//Show's the Person's Detail to the screen
		void showPersonDetail(){
			cout << "Name\t\t:: " << name << endl;
			Sleep(800);
			cout << "Profession\t\t:: " << job << endl;
			Sleep(800);
			cout << "Adhar Card Number\t:: " << id << endl;
			Sleep(800);
			cout << "Address\t\t:: " << address << endl;
			Sleep(800);
		}
};

class zeroTax : public person {
	public : 
		void showTax(){
			cout << "\t----> No Income Tax\n" << endl;
		}
};

class normalTax : public person{
	private:
		int salary;
	public :
		int getSalary(){
			return salary;
		}

		void setSalary(int salary){
			this -> salary = salary;
		}

		void inputSalary(){
			cout << "\tWhat is your Salary\t:: ";
			int x;
			cin >> x;
			setSalary(x);
		}

		void showTax(){
			double tax;
			tax = getSalary()*((double)0.2);
			cout << "\t----> Tax :: " << tax << " Rs.\n" << endl;
		}
};

class highTax : public person{
	private:
		int salary;
	public :
		int getSalary(){
			return salary;
		}

		void setSalary(int salary){
			this -> salary = salary;
		}

		void inputSalary(){
			cout << "\tWhat is your Salary\t:: ";
			int x;
			cin >> x;
			setSalary(x);
		}

		void showTax(){
			double tax;	
			tax = getSalary()*((double)0.3);
			cout << "\t----> Tax :: " << tax << " Rs.\n" << endl;
		}
};

int main(){
	// number inputed in the termial like (1 , 2 , 3)
	int number_input;
	zeroTax z[10007];	
	normalTax n[10007];
	highTax h[10007];
	int counter_zero = 0 , counter_normal = 0 , counter_high = 0;

	do {
		cout << "\n\t\t\t\t\t\t********************* WELCOME TO INCOME TAX CALCULATOR *********************\n\n" << endl; 
		Sleep(1400);
		cout << "What do you want to do?\n";
		Sleep(1400);
	   	cout << " 1.Enter Your Data (If new)\n ";
		Sleep(1400);
		cout << "2.Search\n ";
		Sleep(1400);
		cout << "3.Exit.\n\n";
		Sleep(1400);
		cout << "Choose From (1/2/3) :: "; 
		cin >> number_input;

		switch(number_input){
			case 1: {
						system("cls");	
						cout << "\n\t\t\t\t\t\t********************* WELCOME TO INCOME TAX CALCULATOR *********************\n" << endl; 
						Sleep(1500);
						cout << "\n\t\t\t\t\t\t\t****************** Enter The Data Below ******************\n\n";
						Sleep(1500);
						cout << "\n\n   *Tax Rate*\n-> Students :: 0%" << endl;
						cout << "\n-> Farmer :: 0%" << endl;
						cout << "\n-> Labour :: 0%" << endl;
						cout << "\n-> Buisness :: 30%" << endl;
						cout << "\n-> Other :: 20%\n\n" << endl;
						Sleep(1500);
						cout << " Number of family members :: ";
						int number_of_members;
						cin >> number_of_members;
						cout << endl;

						for(int i = 0 ; i < number_of_members ; i++){
							//person temp;
							string job;
							cout << "\n\tProfession of Person " << i+1 << "\t\t:: ";
							cin >> job;
							//temp.getPerson();

							if (job == "student" || job == "farmer" || job == "labour" || job == "Student" || job == "Farmer" || job == "Labour"){
								z[counter_zero].getPerson();
								z[counter_zero].setJob(job);
								z[counter_zero].showTax();
								counter_zero++;
							} else if (job == "buisness" || job == "Buisness"){
								h[counter_high].getPerson();
								h[counter_high].setJob(job);

								h[counter_high].inputSalary();
								h[counter_high].showTax();
								counter_high++;
							} else {
								n[counter_normal].getPerson();
								n[counter_normal].setJob(job);

								n[counter_normal].inputSalary();
								n[counter_normal].showTax();
								counter_normal;
							}
						}

						break;
					}

			case 2: {
						ll id;
						cout << "\tEnter your Adhar Card Number (ID)\t:: ";
						cin >> id;

						bool done = false;
						for(int i = 0 ; i < 10007 ; i++){
							if (counter_zero >= i && z[i].getId() == id) {
								z[i].showPersonDetail();
								z[i].showTax();
								cout << endl;
								done = true;
								break;
							} else if (counter_normal >= i && n[i].getId() == id){
								n[i].showPersonDetail();
								n[i].showTax();
								cout << endl;
								done = true;
								break;
							} else if (counter_high >= i && h[i].getId() == id) {
								h[i].showPersonDetail();
								h[i].showTax();
								cout << endl;
								done = true;
								break;
							}
						}

						if(!done){
							cout << "\n\tError :: Your Adhar Card Number is not stored in our system. Please enter your new record" << endl;
						}

						break;
					}
			case 3:	break;

			default: cout << "Enter the correct option." << endl;
					 break;
		}

		if(number_input == 3 && (number_input != 1 || number_input != 2)){
			break;
		}

		cout << "Wanted to do again enter (Yes/No) :: " ;
		string x;
		cin >> x;
		if(x == "No" || x == "no"){break;}

		system("cls");

	} while(true);

	return 0;
}
