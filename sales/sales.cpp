#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Data {
    private:
        string city;
        string food;
        double price;
        double quantity;

    public:
        Data(istream& str);

        double totalPrice() {
            return this->price * this->quantity;
        }

        string getCity() {
            return this->city;
        }
};

class Result {
    private:
        string cityName;
        double revenue;

    public:
        Result(string cityName_, double revenue_) {
            
            this->cityName = cityName_;
            this->revenue = revenue_;
        }
        double addingRevenue(double revenue_) {
            return this->revenue += revenue_;
        }
        string getCityName() const {  //without const the compareByCityName function does not work
            return this->cityName;
        }
        double getRevenue() {
            return this->revenue;
        }

};

bool compareByCityName(const Result& a, const Result& b) {
    return a.getCityName() < b.getCityName();
}

Data::Data(istream& str)
{
    string line;
    getline(str, line);

    istringstream iss(line);
    iss >> city >> food >> price >> quantity;
}
    

int main()
{
    int numberOfRows;
    cin >> numberOfRows;
    cin.ignore();

    vector<Data> array;

    vector<string> uniqueArray;

    int i = 0;
    while (i < numberOfRows) {
        Data n1(cin);
        array.push_back(n1);
        i++;
    }

    for (int i = 0; i < numberOfRows; i++) {
        bool statement = find(uniqueArray.begin(), uniqueArray.end(), array[i].getCity()) != uniqueArray.end();
       
        if (!statement) {
            uniqueArray.push_back(array[i].getCity());
        }
    }

    vector <Result> arrayOfRes;

    for (int i = 0; i < uniqueArray.size(); i++) {
        Result r1(uniqueArray[i],0);
        for (int g = 0; g < array.size(); g++) {
            
            if (uniqueArray[i] == array[g].getCity()) {
                r1.addingRevenue(array[g].totalPrice());
            }
          
        }
        arrayOfRes.push_back(r1);
    }
    sort(arrayOfRes.begin(), arrayOfRes.end(), compareByCityName);

    for (int i = 0; i < arrayOfRes.size(); i++) {
        cout << fixed << setprecision(2) << arrayOfRes[i].getCityName()<< " -> " << arrayOfRes[i].getRevenue() << endl;
    }

}
/*
10
Sofia beer 10 2
Sofia beer 10 1
Sofia beer 10 1
Sofia beer 10 1
Provadia bread 15 3
Shumen bread 10 2
Sofia beer 10 1
Sofia bread 10 2
Sofia bread 10 1
Provadia bread 15 1
*/
