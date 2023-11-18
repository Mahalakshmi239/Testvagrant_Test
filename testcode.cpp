#include<bits/stdc++.h>
using namespace std;

string solvegst(vector<string> &prod,vector<int>& quantity,vector<int>& gst){
    int maxgst = 0;
    string maxProd = prod[0];
    int n=4;
    for(int i=0;i<n;i++){
        if(quantity[i]>0){

            maxgst = max(maxgst,gst[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(maxgst == gst[i]){
            maxProd = prod[i];
        }
    }
    return maxProd;
}


int solve(vector<string> &prod,vector<int> &cost, vector<int>& quantity,vector<int>& gst){
    int discount = 0.05;
    int totalAmount = 0;

    for(int i=0;i<4;i++){
        if(cost[i] >= 500){
            totalAmount += (cost[i]*quantity[i]) - (cost[i]*discount) + (cost[i]*(gst[i]/100));
        }
        else
        {
            totalAmount += (cost[i]*quantity[i]) + (cost[i]*(gst[i]/100));
        }
        
    }
    return totalAmount;

}

int main(){

    vector<string> prod;
    vector<int> cost;
    vector<int> quantity;
    vector<int> gst;
    int n = 4;

    //we can store the input from the user in single for loop 
    
    //storing product list
    prod.push_back("leather wallet");
    prod.push_back("umbrella");
    prod.push_back("cigarette");
    prod.push_back("honey");

    //storing cost of products
    cost.push_back(1100);
    cost.push_back(900);
    cost.push_back(200);
    cost.push_back(100);

    //storing quantity
    quantity.push_back(1);
    quantity.push_back(4);
    quantity.push_back(3);
    quantity.push_back(2);

    //storing gst
    gst.push_back(18);
    gst.push_back(12);
    gst.push_back(28);
    gst.push_back(0);


    int total = solve(prod,cost,quantity,gst);
    string maxgst = solvegst(prod,quantity,gst);

    cout<<"total amount is   "<<total<<endl;
    cout<<"maximum gst paid for  "<<maxgst<<endl;

    return 0;

}
