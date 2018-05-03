#include <iostream>
#include <fstream>
 #include <limits>
 #include <bits/stdc++.h>


using namespace std;
int vert;

void pVert(){
    
    cout<<"vert is"<< vert <<"";
}
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX;
   int min_index;
  
   for (int v = 0; v < vert; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

void printPath(int parent[], int j){
            string alphabet[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
   
     if (parent[j] == - 1)
        return;
 
    printPath(parent, parent[j]);
 
    
    cout << "Path Taken: " << alphabet[j] <<endl;
}
int printSolution(int dist[], int n, int parent[])
{
    ofstream myfile;
    myfile.open ("example.txt"); 
        string alphabet[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    int src = 0;
   
    for (int i = 1; i < vert; i++)
    {
         cout << alphabet[0] <<"-->" <<alphabet[i] << " Distance is: " <<dist[i]<<endl;
          cout << "Path Taken: " << alphabet[0] <<endl;
         printPath(parent, i);
    }
    myfile.close();
}




int main()
{
    int num;
    ifstream inFile; 
	inFile.open("graph.txt");
	if(!inFile){
		
		cout<<"Unable to open the text file " <<endl;
		exit(1);
		
	}
	

	
	int maxSize;
	int src = 0;
	inFile >> maxSize;
		vert = maxSize;
	int a[maxSize][maxSize];






	for(int i = 0; i < maxSize ; i++){
	    for(int j=0; j< maxSize; j++){
	        a[i][j] = 0;
	        a[j][i] = 0;
	    }
	}
	int count = maxSize;
	for(int i =0; i< maxSize -1 ; i++){
	    for( int j=i+1; j<maxSize; j++){

	            
	        inFile >> num;
	        cout<< num <<""<< endl;
	        a[i][j] = num;
	        a[j][i] = num;
	       
	        }
	    }
	    
	

	for(int k=0; k<maxSize; k++)    
	{
		for(int z=0; z<maxSize; z++) 
		{
			cout << a[k][z]  << "  ";
		}
		cout << endl;
	}
	
	
	
	
	
	 int dist[vert];   
  
     bool sptSet[vert]; 
    int super[vert];
     for (int q = 0; q < vert; q++)
        dist[q] = INT_MAX, sptSet[q] = false, super[0]=-1;
  
     dist[src] = 0;
  
     for (int count = 0; count < vert-1; count++)
     {
      
       int u = minDistance(dist, sptSet);
  
       sptSet[u] = true;
  
       for (int v = 0; v < vert; v++)
  
         if (!sptSet[v] && a[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+a[u][v] < dist[v]){
                                           super[v]= u;
            dist[v] = dist[u] + a[u][v];
     }
     }
  
  printSolution(dist, vert, super);
	

}
