/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: noor_
 *
 * Created on 11 May 2021, 15:46
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int day;

class Nutrition {
protected:
	string foods[10];
	double calories[1000];
	int iter;
public:
	Nutrition() {
		for (int i = 0; i < 10; i++) {
			foods[i] = "";
			calories[i] = 0;
		}
		iter = 0;
		getFoods();
	}
	// Get all foods from txt file
	void getFoods() {
		ifstream file;
		file.open("foods.txt");
		if (file.is_open()) {
			file >> iter;
			for (int i = 0; i < iter; i++) {
				file >> foods[i];
				file >> calories[i];
			}
			file.close();
		}
		else {
			cout << "File 'foods.txt' can't be opened!" << endl;
			system("pause");
		}
	}
	// Save all foods in txt file
	void saveFoods() {
		ofstream file;
		file.open("foods.txt");
		file << iter << endl;
		if (file.is_open()) {
			for (int i = 0; i < iter; i++) {
				file << foods[i] << endl;
				file << calories[i] << endl;
			}
			file.close();
		}
		else {
			cout << "File 'foods.txt' can't be opened!" << endl;
			system("pause");
		}
	}
	// Method for add new food
	void addFood() {
		cout << "Name of food: ";
		cin >> foods[iter];
		cout << "\nFood calories: ";
		cin >> calories[iter];
		iter++;
		saveFoods();
	}
	// Edit calories for food
	void editFood() {
	az:
		string food;
		bool exist = false;
		cout << "What food you like to edit: "; cin >> food;
		for (int i = 0; i < 10; i++) {
			if (foods[i] == food) {
				cout << "\nSet new calories for this food: ";
				cin >> calories[i];
				exist = true;
			}
		}
		if (!exist) {
			cout << "\nFood with this name doesn't exist!" << endl;
			system("pause");
			int n;
			cout << "\nDo you like to try again?";
			cout << "\n1. Yes";
			cout << "\n2. No";
			cout << "\nOption: "; cin >> n;
			switch (n)
			{
			case 1: {
				goto az;
				break;
			}
			case 2: {
				break;
			}
			default: {
				break;
			}
			}
		}
		saveFoods();
	}
	// Delete food from list
	void deleteFood() {
	az:
		string food;
		bool exist = false;
		int number;
		cout << "What food you like to delete: "; cin >> food;
		for (int i = 0; i < 1000; i++) {
			if (foods[i] == food) {
				exist = true;
				number = i;
				break;
			}
		}
		if (exist) {
			for (int i = number; i < 1000; i++) {
				if (i < 999) {
					foods[i] = foods[i + 1];
					calories[i] = calories[i + 1];
				}
				else {
					foods[i] = "";
					calories[i] = 0;
				}
			}
			iter--;
		}
		else {
			cout << "\nFood with this name doesn't exist!" << endl;
			system("pause");
			int n;
			cout << "\nDo you like to try again?";
			cout << "\n1. Yes";
			cout << "\n2. No";
			cout << "\nOption: "; cin >> n;
			switch (n)
			{
			case 1: {
				goto az;
				break;
			}
			case 2: {
				break;
			}
			default: {
				break;
			}
			}
		}
		saveFoods();
	}
	// Display all foods
	void viewFood() {
		cout << setw(5) << "Nr." << setw(20) << "Food name" << setw(20) << "Calories" << endl; // setw() - Sets the field width to be used on output operations.
		for (int i = 0; i < iter; i++)
			cout << setw(5) << i + 1 << ". " << setw(20) << foods[i] << setw(20) << calories[i] << endl;
	}
	// Search method for foods
	void searchFood() {
	ag:
		string food;
		bool exist = false;
		int number;
		cout << "Name of food: "; cin >> food;
		for (int i = 0; i < 1000; i++) {
			if (foods[i] == food) {
				exist = true;
				number = i;
				break;
			}
		}
		if (exist) {
			cout << "Name: " << foods[number] << endl;
			cout << "Calories: " << calories[number] << endl;
		}
		else {
			cout << "\nFood with this name doesn't exist!" << endl;
			system("pause");
			int n;
			cout << "\nDo you like to try again?";
			cout << "\n1. Yes";
			cout << "\n2. No";
			cout << "\nOption: "; cin >> n;
			switch (n)
			{
			case 1: {
				goto ag;
				break;
			}
			case 2: {
				break;
			}
			default: {
				break;
			}
			}
		}

	}
};

class Diet : public Nutrition {
protected:
	string breakfast[1000], lunch[1000], dinner[1000], supper[1000];
	double breakfastCalories[1000], lunchCalories[1000], dinnerCalories[1000], supperCalories[1000];
	int iter1, iter2, iter3, iter4;
	double caloriesDay[30];
public:
	Diet() {
		for (int i = 0; i < 1000; i++) {
			breakfast[i] = "";
			lunch[i] = "";
			dinner[i] = "";
			supper[i] = "";

			breakfastCalories[i] = 0;
			lunchCalories[i] = 0;
			dinnerCalories[i] = 0;
			supperCalories[i] = 0;
		}

		for (int i = 0; i < 30; i++) {
			caloriesDay[i] = 0;
		}

		iter1 = 0; iter2 = 0; iter3 = 0; iter4 = 0;
	}
	// Reset method when new month start
	void resetMonth() {
		for (int i = 0; i < 30; i++)
			caloriesDay[i] = 0;
	}
	// Method for add meal
	bool setMeal() {
	az:
		string food;
		int number;
		bool exist = false;
		cout << "What food you like to add: "; cin >> food;
		for (int i = 0; i < 1000; i++) {
			if (foods[i] == food) {
				exist = true;
				number = i;
				break;
			}
		}

		if (!exist) {
			cout << "\nFood with this name doesn't exist!" << endl;
			system("pause");
			int n;
			cout << "\nDo you like to try again?";
			cout << "\n1. Yes";
			cout << "\n2. No";
			cout << "\nOption: "; cin >> n;
			switch (n)
			{
			case 1: {
				goto az;
				break;
			}
			case 2: {
				return false;
				break;
			}
			default: {
				return false;
				break;
			}
			}
		}

	ax:
		int m;
		cout << "\nWhere do you like to add food?" << endl;
		cout << "1. Breakfast\n";
		cout << "2. Lunch\n";
		cout << "3. Dinner\n";
		cout << "4. Supper\n";
		cout << "Option: "; cin >> m;
		switch (m)
		{
		case 1: {
			breakfast[iter1] = foods[number];
			breakfastCalories[iter1] = calories[number];
			iter1++;
			break;
		}
		case 2: {
			lunch[iter2] = foods[number];
			lunchCalories[iter2] = calories[number];
			iter2++;
			break;
		}
		case 3: {
			dinner[iter3] = foods[number];
			dinnerCalories[iter3] = calories[number];
			iter3++;
			break;
		}
		case 4: {
			supper[iter4] = foods[number];
			supperCalories[iter4] = calories[number];
			iter4++;
			break;
		}
		default: {
			cout << "Wrong choice!" << endl;
			system("pause");
			goto ax;
		}
		}
		calcCaloriesDay();
		return true;
	}
	// Method for remove meal
	bool removeMeal() {
	az:
		string food;
		int number, meal;
		bool exist = false;
		cout << "What food you like to remove: "; cin >> food;
		int op;
	av:
		cout << "\nFrom: " << endl;
		cout << "1. Breakfast" << endl;
		cout << "2. Lunch" << endl;
		cout << "3. Dinner" << endl;
		cout << "4. Supper" << endl;
		cout << "Option: "; cin >> op;
		switch (op) {
		case 1: {
			for (int i = 0; i < 1000; i++) {
				if (breakfast[i] == food) {
					exist = true;
					number = i;
					meal = 1;
					break;
				}
			}
			break;
		}
		case 2: {
			for (int i = 0; i < 1000; i++) {
				if (lunch[i] == food) {
					exist = true;
					number = i;
					meal = 2;
					break;
				}
			}
			break;
		}
		case 3: {
			for (int i = 0; i < 1000; i++) {
				if (dinner[i] == food) {
					exist = true;
					number = i;
					meal = 3;
					break;
				}
			}
			break;
		}
		case 4: {
			for (int i = 0; i < 1000; i++) {
				if (supper[i] == food) {
					exist = true;
					number = i;
					meal = 4;
					break;
				}
			}
			break;
		}
		default: {
			cout << "\nWrong choise!" << endl;
			system("pause");
			goto av;
			break;
		}
		}


		if (!exist) {
			cout << "\nFood with this name doesn't exist in your meal!" << endl;
			system("pause");
			int n;
			cout << "\nDo you like to try again?";
			cout << "\n1. Yes";
			cout << "\n2. No";
			cout << "\nOption: "; cin >> n;
			switch (n)
			{
			case 1: {
				goto az;
				break;
			}
			case 2: {
				return false;
				break;
			}
			default: {
				return false;
				break;
			}
			}
		}

		switch (meal) {
		case 1: {
			for (int i = number; i < 1000; i++) {
				if (i < 999) {
					breakfast[i] = breakfast[i + 1];
					breakfastCalories[i] = breakfastCalories[i + 1];
				}
				else {
					breakfast[i] = "";
					breakfastCalories[i] = 0;
				}
			}
			iter1--;
			break;
		}
		case 2: {
			for (int i = number; i < 1000; i++) {
				if (i < 999) {
					lunch[i] = lunch[i + 1];
					lunchCalories[i] = lunchCalories[i + 1];
				}
				else {
					lunch[i] = "";
					lunchCalories[i] = 0;
				}
			}
			iter2--;
			break;
		}
		case 3: {
			for (int i = number; i < 1000; i++) {
				if (i < 999) {
					dinner[i] = dinner[i + 1];
					dinnerCalories[i] = dinnerCalories[i + 1];
				}
				else {
					dinner[i] = "";
					dinnerCalories[i] = 0;
				}
			}
			iter3--;
			break;
		}
		case 4: {
			for (int i = number; i < 1000; i++) {
				if (i < 999) {
					supper[i] = supper[i + 1];
					supperCalories[i] = supperCalories[i + 1];
				}
				else {
					supper[i] = "";
					supperCalories[i] = 0;
				}
			}
			iter4--;
			break;
		}
		}
		calcCaloriesDay();
		return true;
	}
	// Method for calculating consumed calories
	double calcCaloriesDay() {
		double sum = 0;
		for (int i = 0; i < iter1; i++)
			sum += breakfastCalories[i];
		for (int i = 0; i < iter2; i++)
			sum += lunchCalories[i];
		for (int i = 0; i < iter3; i++)
			sum += dinnerCalories[i];
		for (int i = 0; i < iter4; i++)
			sum += supperCalories[i];
		caloriesDay[day] = sum;
		saveConsum();
		return sum;
	}
	// Display monthly consumed calories
	void calcCaloriesMonth() {
		double sum = 0;
		for (int i = 0; i < 30; i++)
			sum += caloriesDay[i];

		cout << setw(7) << "Day nr." << setw(20) << "Calories consumated" << endl;
		for (int i = 0; i < 30; i++) {
			cout << setw(7) << i + 1 << setw(20) << caloriesDay[i] << endl;
		}

		cout << "\nTotal this month: " << sum << endl;

	}
	// Get calories that have been consumed from txt file
	void getConsum() {
		ifstream file;
		file.open("consum.txt");
		if (file.is_open()) {
			for (int i = 0; i < 30; i++)
				file >> caloriesDay[i];
			file.close();
		}
		else {
			cout << "File can't be opened!" << endl;
			system("pause");
		}
	}
	// Save calories that have been consumed in txt file
	void saveConsum() {
		ofstream file;
		file.open("consum.txt");
		if (file.is_open()) {
			for (int i = 0; i < 30; i++) {
				file << caloriesDay[i] << endl;
			}
			file.close();
		}
		else {
			cout << "File can't be opened!" << endl;
			system("pause");
		}
	}
};


class Exercise {
protected:
	double walking = 5, running = 12, freestyle = 10;
	double dayCaloriesBurnt[30];
public:
	Exercise() {
		for (int i = 0; i < 30; i++)
			dayCaloriesBurnt[i] = 0;
	}
	// Rest method when new month start
	void resetMonthExercise() {
		for (int i = 0; i < 30; i++)
			dayCaloriesBurnt[i] = 0;
		saveStats();
	}
	// Calculating burnt calories [method for calcDayBurnt()]
	double calcExercise(string type, int duration) {
		if (type == "walking") {
			return walking * duration;
		}
		if (type == "running") {
			return running * duration;
		}
		if (type == "freestyle") {
			return freestyle * duration;
		}
		cout << "Wrong type of exercise!";
		return 0;
	}
	// Display monthly calories burnt
	void calcMonthBurnt() {
		double sum = 0;
		for (int i = 0; i < 30; i++) {
			sum += dayCaloriesBurnt[i];
		}

		cout << setw(8) << "Day nr." << setw(15) << "Calories burnt" << endl;
		for (int i = 0; i < 30; i++) {
			cout << setw(8) << i + 1 << setw(15) << dayCaloriesBurnt[i] << endl;
		}

		cout << "\nTotal this month: " << sum << endl;
	}
	// Method for calculating calories depending on the type of exercise
	void calcDayBurnt() {
		string type;
		int n;
		int duration;
	ab:
		cout << "What type of exercise:\n";
		cout << "1. Walking" << endl;
		cout << "2. Running" << endl;
		cout << "3. Freestyle Activity" << endl;
		cout << "Option: "; cin >> n;
		switch (n)
		{
		case 1: {
			type = "walking";
			break;
		}
		case 2: {
			type = "running";
			break;
		}
		case 3: {
			type = "freestyle";
			break;
		}
		default: {
			cout << "\nWrong choise!" << endl;
			system("pause");
			goto ab;
		}
		}

		cout << "\nDuration (minute): "; cin >> duration;
		dayCaloriesBurnt[day] += calcExercise(type, duration);
		saveStats();
	}
	// Get information about burnt calories from txt file
	void getStats() {
		ifstream file;
		file.open("stats.txt");
		if (file.is_open()) {
			for (int i = 0; i < 30; i++)
				file >> dayCaloriesBurnt[i];
			file.close();
		}
		else {
			cout << "File can't be opened!" << endl;
			system("pause");
		}
	}
	// Save information about burnt calories in txt file
	void saveStats() {
		ofstream file;
		file.open("stats.txt");
		if (file.is_open()) {
			for (int i = 0; i < 30; i++) {
				file << dayCaloriesBurnt[i] << endl;
			}
			file.close();
		}
		else {
			cout << "File can't be opened!" << endl;
			system("pause");
		}
	}

};

class Person : public Diet, public Exercise{
protected:
	string name, gender;
	int age;
	double weight, height;
	double target, consumed, burnt;
public:
	Person(){
		name = "";
		gender = "";
		age = 0;
		weight = 0;
		height = 0;
		target = 0;
		consumed = 0;
		burnt = 0;
	}
	void setHeight(double height) {
		this->height = height;
	}

	void setweight(double weight) {
		this->weight = weight;
	}
	// Add information about person
	void addInfo() {
		cout << "Enter your name: "; cin >> name;
		int n;
	az:
		cout << "\nYour gender:\n";
		cout << "1. Male" << endl;
		cout << "2. Female" << endl;
		cout << "Option: "; cin >> n;
		if (n == 1) {
			gender = "Male";
		}
		else {
			if (n == 2) {
				gender = "Female";
			}
			else
			{
				cout << "Wrong choice!" << endl;
				system("pause");
				goto az;
			}
		}
		cout << "\nEnter your age: "; cin >> age;
		cout << "\nEnter your weight (kg): "; cin >> weight;
		cout << "\nEnter your height (meter): "; cin >> height;
		savePersonInfo();
	}
        void changeInfo() {
		int n;
	ax:
		cout << "What you like to change?" << endl;
		cout << "1. Name\n";
		cout << "2. Gender\n";
		cout << "3. Age\n";
		cout << "4. Weight\n";
		cout << "5. Height\n";
		cout << "Option: "; cin >> n;
		switch (n)
		{
		case 1: {
			cout << "Enter your name: "; cin >> name;
			break;
		}
		case 2: {
			int m;
		bz:
			cout << "\nYour gender:\n";
			cout << "1. Male" << endl;
			cout << "2. Female" << endl;
			cout << "Option: "; cin >> m;
			if (m == 1) {
				gender = "Male";
			}
			else {
				if (m == 2) {
					gender = "Female";
				}
				else
				{
					cout << "Wrong choice!" << endl;
					system("pause");
					goto bz;
				}
			}
			break;
		}
		case 3: {
			cout << "\nEnter your age: "; cin >> age;
			break;
		}
		case 4: {
			cout << "\nEnter your weight (kg): "; cin >> weight;
			break;
		}
		case 5: {
			cout << "\nEnter your height (meter): "; cin >> height;
			break;
		}
		default: {
			cout << "Wrong choice!" << endl;
			system("pause");
			goto ax;
		}
		}
		int x;
		cout << "\nWould you like to change anything else?";
		cout << "\n1. Yes";
		cout << "\n2. No";
		cout << "\nOption: "; cin >> x;
		switch (x) {
		case 1: {
			goto ax;
			break;
		}
		case 2: {
                        break;
		}
		}
        }
	// BMI
	double BMI() {
		return weight / (height * height);
	}
	// Method for set target (calories)
	void setTarget() {
		cout << "Set targeted calories consumed per day: "; cin >> target;
		savePersonInfo();
	}

    string CheckTarget(){
		if (consumed > target) {
			cout << "The targeted calories is exceeded!" << endl;
		} else {
			cout << "The targeted calories isn't exceeded!" << endl;
		}
    }

	// Method for displaying information about person
	void view() {
		burnt = dayCaloriesBurnt[day];
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Age: " << age << endl;
		cout << "Weight: " << weight << endl;
		cout << "Height: " << height << endl;
		cout << "Target: " << target << endl;
		cout << "Today calories consumed: " << caloriesDay[day] << endl;
		cout << "Today    burnt: " << burnt << endl;
		CheckTarget();
	}
	// Get information about person from txt file
	void getPersonInfo() {
		ifstream file;
		file.open("personInfo.txt");
		if (file.is_open()) {
			file >> day;
			file >> name;
			file >> gender;
			file >> age;
			file >> weight;
			file >> height;
			file >> target;
			file.close();
		}
		else {
			cout << "File 'personInfo.txt' can't be opened!" << endl;
			system("pause");
		}
	}
	// Save information about person in txt file
	void savePersonInfo(){
		ofstream file;
		file.open("personInfo.txt");
		if (file.is_open()) {
			file << day << endl;
			file << name << endl;
			file << gender << endl;
			file << age << endl;
			file << weight << endl;
			file << height << endl;
			file << target << endl;
			file.close();
		}
		else {
			cout << "File 'personInfo.txt' can't be opened!" << endl;
			system("pause");
		}
	}
};

int main() {
	Person* person = new Person();
	// Get information from txt files
	person->getStats();
	person->getFoods();
	person->getPersonInfo();
	person->getConsum();
	// ----------------------------------
        

	// Start program
	bool run = true;
	while (run) {
		int n;
		system("cls");
		cout << "\nDay: " << day + 1 << endl; // first day is 0, thus day + 1 to display first day: 1
		cout << "\n--== Menu ==--" << endl;
		cout << "1. User Profile Management" << endl;
		cout << "2. Nutrition Facts and Details Management" << endl;
		cout << "3. Diet Tracking" << endl;
		cout << "4. Exercise Tracking" << endl;
		cout << "5. Exit" << endl;
		cout << "99. NEXT DAY!" << endl;
		cout << "Options: "; cin >> n;
		switch (n) {
		case 1: {
			system("cls"); // Function to clear CMD
			bool runProfile = true;
			while (runProfile) {
				int profileOption;
				cout << "\n\n1. Add information" << endl;
				cout << "2. Edit information" << endl;
				cout << "3. BMI" << endl;
				cout << "4. Set targeted calories consumed per day" << endl;
				cout << "5. View all information" << endl;
				cout << "6. Back to menu" << endl;
				cout << "Option: "; cin >> profileOption;
				switch (profileOption) {
				case 1: {
					cout << endl;
					person->addInfo();
					break;
				}
				case 2: {
					cout << endl;
					person->changeInfo();
					break;
				}
				case 3: {
					cout << endl;
					cout << "BMI: " << person->BMI();
					break;
				}
				case 4: {
					cout << endl;
					person->setTarget();
					break;
				}
				case 5: {
					cout << endl;
					person->view();
					break;
				}
				case 6: {
					runProfile = false;
					break;
				}
				default: {
					cout << endl;
					cout << "\nWrong choise!" << endl;
					system("pause");
				}
				}
			}
			break;
		}

		case 2: {
			system("cls");
			bool runNutrition = true;
			while (runNutrition) {
				int NutritionOption;
				cout << "\n\n1. Add food" << endl;
				cout << "2. Edit food" << endl;
				cout << "3. Delete food" << endl;
				cout << "4. Search food" << endl;
				cout << "5. View all foods" << endl;
				cout << "6. Back to menu" << endl;
				cout << "Option: "; cin >> NutritionOption;
				switch (NutritionOption) {
				case 1: {
					cout << endl;
					person->addFood();
					break;
				}
				case 2: {
					cout << endl;
					person->editFood();
					break;
				}
				case 3: {
					cout << endl;
					person->deleteFood();
					break;
				}
				case 4: {
					cout << endl;
					person->searchFood();
					break;
				}
				case 5: {
					cout << endl;
					person->viewFood();
					break;
				}
				case 6: {
					runNutrition = false;
					break;
				}
				default: {
					cout << endl;
					cout << "\nWrong choise!" << endl;
					system("pause");
				}
				}
			}
			break;
		}


		case 3: {
			system("cls");
			bool runDiet = true;
			while (runDiet) {
				int DietOption;
				cout << "\n\n1. Add meal" << endl;
				cout << "2. Remove meal" << endl;
				cout << "3. View monthly calories consumation" << endl;
				cout << "4. Back to menu" << endl;
				cout << "Option: "; cin >> DietOption;
				switch (DietOption) {
				case 1: {
					cout << endl;
					person->setMeal();
					break;
				}
				case 2: {
					cout << endl;
					person->removeMeal();
					break;
				}
				case 3: {
					cout << endl;
					person->calcCaloriesMonth();
					break;
				}
				case 4: {
					runDiet = false;
					break;
				}
				default: {
					cout << endl;
					cout << "\nWrong choise!" << endl;
					system("pause");
				}
				}
			}
			break;
		}

		case 4: {
			system("cls");
			bool runExercise = true;
			while (runExercise) {
				int ExerciseOption;
				cout << "\n\n1. Add exercise" << endl;
				cout << "2. View monthly calories burnt" << endl;
				cout << "3. Back to menu" << endl;
				cout << "Option: "; cin >> ExerciseOption;
				switch (ExerciseOption) {
				case 1: {
					cout << endl;
					person->calcDayBurnt();
					break;
				}
				case 2: {
					cout << endl;
					person->calcMonthBurnt();
					break;
				}
				case 3: {
					runExercise = false;
					break;
				}
				default: {
					cout << endl;
					cout << "\nWrong choise!" << endl;
					system("pause");
				}
				}
			}
			break;
		}
		case 99: {
			day++;
			if (day > 29) {
				day = 0;
				person->resetMonth();
				person->resetMonthExercise();
			}
			person->saveStats();
			break;
		}

		case 5: {
			run = false;
			break;
		}

		default: {
			cout << "\nWrong choise!" << endl;
			system("pause");
		}
		}
	}

	return 0;
}