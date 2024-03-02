//============================================================================
// Name        : Proje_17.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

string duzenle(string s1){
    string result;
    for(unsigned int i=0; i<s1.length(); i++){
        if(s1[i]!='"'){
            result+=s1[i];
        }
    }
    return result;
}

int choosing_subject(){
	int choose;
	cout << "Welcome to our program,please choose a subject." << endl;
	cout << "1-Math , 2-Reading , 3-Writing" << endl;
	cin >> choose;
	return choose;
}

int choosing_gender(){
	int choose;
	cout << "Please choose a gender." << endl;
	cout << "1-Male, 2-Female" << endl;
	cin >> choose;
	return choose;
}

int randomscorecounter(){
	const int numScores = 100;
	const int minScore = 1;
	const int maxScore = 100;
	int total_score = 0;
	srand(time(0));
	for(int i = 0; i < numScores; i++){
		int score = minScore + (rand() % (maxScore));
		total_score += score;
	}
	double average_score = total_score / numScores;
	return average_score;
}

void readGroupFile(string data,double average_value,int gender,int subject){
	double total_a_math_male = 0,total_a_math_female = 0;
	double num_a_math_male = 0,num_a_math_female = 0;
	double total_b_math_male = 0,total_b_math_female = 0;
	double num_b_math_male = 0,num_b_math_female = 0;
	double total_c_math_male = 0,total_c_math_female = 0;
	double num_c_math_male = 0,num_c_math_female = 0;
	double total_d_math_male = 0,total_d_math_female = 0;
	double num_d_math_male = 0,num_d_math_female = 0;
	double total_e_math_male = 0,total_e_math_female = 0;
	double num_e_math_male = 0,num_e_math_female = 0;
	ifstream dosyaOku;
	dosyaOku.open(data);
	vector<string> lines;
	if(dosyaOku){
		string line;
		while(getline(dosyaOku, line)){
			stringstream ss(line);
			string kelime;
			while(getline(ss,kelime,' ')){
				lines.push_back(kelime);
			}
		}
	}
	dosyaOku.close();
	for(unsigned int i = 0; i < lines.size(); i++){
		if("A" == lines[i]){
			if("male" == lines[i-2]){
				total_a_math_male += stoi(lines[i+1]);num_a_math_male++;
			}else{total_a_math_female += stoi(lines[i+1]);num_a_math_female++;}
		}
		if("B" == lines[i]){
			if("male" == lines[i-2]){
				total_b_math_male += stoi(lines[i+1]);num_b_math_male++;
			}else{total_b_math_female += stoi(lines[i+1]);num_b_math_female++;}
		}
		if("C" == lines[i]){
			if("male" == lines[i-2]){
				total_c_math_male += stoi(lines[i+1]);num_c_math_male++;
			}else{total_c_math_female += stoi(lines[i+1]);num_c_math_female++;}
		}
		if("D" == lines[i]){
			if("male" == lines[i-2]){
				total_d_math_male += stoi(lines[i+1]);num_d_math_male++;
			}else{total_d_math_female += stoi(lines[i+1]);num_d_math_female++;}
		}
		if("E" == lines[i]){
			if("male" == lines[i-2]){
				total_e_math_male += stoi(lines[i+1]);num_e_math_male++;
			}else{total_e_math_female += stoi(lines[i+1]);num_e_math_female++;}
		}
	}
	double avg_a_math_male = total_a_math_male / num_a_math_male, avg_a_math_female = total_a_math_female / num_a_math_female;
	double avg_b_math_male = total_b_math_male / num_b_math_male, avg_b_math_female = total_b_math_female / num_b_math_female;
	double avg_c_math_male = total_c_math_male / num_c_math_male, avg_c_math_female = total_c_math_female / num_c_math_female;
	double avg_d_math_male = total_d_math_male / num_d_math_male, avg_d_math_female = total_d_math_female / num_d_math_female;
	double avg_e_math_male = total_e_math_male / num_e_math_male, avg_e_math_female = total_e_math_female / num_e_math_female;
	cout << "male avg for a :" << avg_a_math_male << " --- " << "female avg for a " << avg_a_math_female << endl;
	cout << "male avg for b :" << avg_b_math_male << " --- " << "female avg for b " << avg_b_math_female << endl;
	cout << "male avg for c :" << avg_c_math_male << " --- " << "female avg for c " << avg_c_math_female << endl;
	cout << "male avg for d :" << avg_d_math_male << " --- " << "female avg for d " << avg_d_math_female << endl;
	cout << "male avg for e :" << avg_e_math_male << " --- " << "female avg for e " << avg_e_math_female << endl;
}


void readDataFromFile(string data , string w_data){
    ifstream dosyaOku;
    ofstream dosyaYaz;
    dosyaOku.open(data);
    dosyaYaz.open(w_data);
    vector<string> lines;
    if(dosyaOku){
        string line;
        while(getline(dosyaOku ,line)){
            stringstream ss(line);
            string kelime;
            while(getline(ss, kelime ,',')){
                    kelime=duzenle(kelime);
                    lines.push_back(kelime);
            	}
        }
        for(unsigned int i = 0; i<=lines.size(); i++){
        if("group A"==lines[i]){
            dosyaYaz << lines[i-1] << " " << lines[i] << " "<< lines[i+4]<< " "<< lines[i+5]<< " "<< lines[i+6]<<endl;
        	}
        if("group B"==lines[i]){
            dosyaYaz << lines[i-1] << " " << lines[i] << " " << lines[i+4]<< " "<<lines[i+5]<< " "<< lines[i+6]<<endl;
        	}
        if("group C"==lines[i]){
            dosyaYaz << lines[i-1] << " " << lines[i] << " "<< lines[i+4]<< " "<<lines[i+5]<< " "<< lines[i+6]<<endl;
       		}
        if("group D"==lines[i]){
            dosyaYaz << lines[i-1] << " " << lines[i]<< " "<< lines[i+4]<< " "<<lines[i+5]<< " "<< lines[i+6]<<endl;
       		}
        if("group E"==lines[i]){
            dosyaYaz << lines[i-1] << " " << lines[i]<< " "<< lines[i+4]<< " "<<lines[i+5]<< " "<< lines[i+6]<<endl;
       		}
        }
    }
    dosyaYaz.close();
    dosyaOku.close();
    }

int main() {
	int subject = choosing_subject();
	int gender = choosing_gender();
	double average_score = randomscorecounter();
//    readDataFromFile("StudentsPerformance.csv" , "group.txt" );
//    readGroupFile("group.txt",average_score,gender,subject);
    return 0;
}
