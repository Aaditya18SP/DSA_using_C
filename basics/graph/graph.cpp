/*************************
 * Student Author Name:
 * Lab Section: 
 * ***********************/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//************************** Node *************************

class Node{		
	public:
	int nodeId;
	Node* neighbourAddr=NULL;
};
//************************** Graph ****************************
class Graph {
	public:
		//add the node with neighborId as the neighbor of nodeId
		void addNeighbor(int nodeId, int neighborId);

		//reads the edge list from file and creates the adjacency list data structure
		void loadGraph(string edgeListFileName);
		
		//writes the adjacency list into the file
		void dumpGraph(string adjListFileName);

		//Prints number of nodes, number of edges, and maximum degree on terminal
		void printGraphInfo();

		//returns the number of neighbor (degree) of a node
		int getNumNeighbors(int nodeId);

		//returns the number of nodes in the graph
		int getNumVertices();

	private:
		vector<Node*> vertices;
		int numberOfEdges;
		int numberOfVertices;
		
};

//1. Adding neighbours
void Graph::addNeighbor(int nodeId, int neighborId){

	int isNeighborAlreadyPresent=0;
	Node* nodePtr= new Node();
	nodePtr->nodeId=neighborId;

	Node* headNodePtr=vertices[nodeId];
	Node* node= headNodePtr->neighbourAddr;
	Node* previousNodePtr=headNodePtr;

	
	//check whether the neighbor id is already present
	while(node!=NULL){
		//cout<<"head node is: "<<headNodePtr->nodeId<< " current neighbor: "<< node->nodeId<<endl;
		
		if(node->nodeId==neighborId){
			isNeighborAlreadyPresent=1;
			break;
		}
		
		node= node->neighbourAddr;
	}
	

	if(!isNeighborAlreadyPresent){

		node=headNodePtr->neighbourAddr;
		if(node!=NULL){
		//cout<<"Next node is: "<<node->nodeId<< endl;

			while(node!=NULL){
				int currentNodeId=node->nodeId;
				Node* nextNode= node->neighbourAddr;
				int nextNodeId;
				if(nextNode==NULL){
					if(neighborId < currentNodeId){
						previousNodePtr->neighbourAddr= nodePtr;
						nodePtr->neighbourAddr=node;

					}else{
						node->neighbourAddr= nodePtr;
						//nodePtr->neighbourAddr=node;
					}
					

				}else{
					nextNodeId=nextNode->nodeId;
					if(neighborId>currentNodeId && neighborId<nextNodeId){
						node->neighbourAddr=nodePtr;
						nodePtr->neighbourAddr=nextNode;//nextNode=nodePtr;
					}
					
				}

				previousNodePtr=node;
				node=nextNode;
			}
			
		}
		else{
			//cout<<"No neighbor node present"<<endl;
			headNodePtr->neighbourAddr=nodePtr;
		}

		/*
		//TODO:Remove later as this is for Testing 
		node=headNodePtr->neighbourAddr;
		cout <<"The neighbors are : ";
		while(node!=NULL){
			cout<<  node->nodeId<< " ";
			node=node->neighbourAddr;
		}
		cout<<endl;
		*/

	}
	/*else{
		cout<<"Neighbor already present"<<endl;
	}
	*/
}

//2. read graph from the file and create the adjacency list
void Graph::loadGraph(string edgeListFileName){

	//
	numberOfEdges=0;
	numberOfVertices=0;

	///Read the contents from the file
	ifstream graphFileContents(edgeListFileName);
	if(!graphFileContents){
		cout<<"Couldn't load the file";
		exit(1);
	}

	string eachLine; 
	//int nodeValue;
	//vector<int> nodeValues;

	//get each line
	while(getline(graphFileContents,eachLine)){
		//cout<<"Each line in graph file is: " << eachLine <<endl;
		numberOfEdges++;
		

		//NodeIds in this line. These are neighbours of each other
		vector<int> nodeIdsVec;

		//create a string stream for each line in order to access each individual node
		istringstream iss(eachLine);
		
		string nodeIdAsString;

		//access each individual character in the line
		while(getline(iss,nodeIdAsString,' ')){
			//cout<<nodeIdAsString<<endl;
			int nodeIdAsInt=stoi(nodeIdAsString);
			//cout <<nodeIdAsInt<<endl;
			nodeIdsVec.push_back(nodeIdAsInt);
			//nodeValues.push_back(nodeIdAsInt);

			if(vertices.size()<=nodeIdAsInt){
				vertices.resize(nodeIdAsInt+1);
				//cout<<"new size of vertices vector is:" << vertices.size()<<endl;
			}
			if(vertices[nodeIdAsInt]==0){
				Node* nodePtr = new Node();
				
				nodePtr->nodeId=nodeIdAsInt;
				vertices[nodeIdAsInt]=nodePtr;
				numberOfVertices++;	
				
				//vertices.insert(vertices.begin()+nodeIdAsInt, nodePtr);
				//cout<<"node inserted at :" << distance(vertices.begin(), vertices.begin()+nodeIdAsInt)<<endl ;
				//cout << "value at inserted position is: "<< vertices[nodeIdAsInt]->nodeId<<endl;
				
			}
		
		}
		//cout<<"size of vertices is: "<<vertices.size()<<endl;
		//cout<<endl;
		//cout<<"the head node is: "<< nodeIdsVec[0]<< " and the neighbor is: "<< nodeIdsVec[1]<<endl;
		//assign the neighbours
		addNeighbor(nodeIdsVec[0],nodeIdsVec[1]);

		//cout<<endl;

		//cout<<"the head node is: "<< nodeIdsVec[1]<< " and the neighbor is: "<< nodeIdsVec[0]<<endl;
		addNeighbor(nodeIdsVec[1],nodeIdsVec[0]);
	}

}

//3. Dump graph into a file
void Graph::dumpGraph(string adjListFileName){
	ofstream myOutputStream;

	myOutputStream.open(adjListFileName);

	for(int index=0;index<vertices.size();index++){
		myOutputStream << index << " : ";

		Node* headNodePtr=vertices[index];

		if(headNodePtr==0){
			myOutputStream<<"NULL";
		}
		else{
			Node* node=headNodePtr->neighbourAddr;
		
			while(node!=NULL){
				myOutputStream << node->nodeId << " ";
				node=node->neighbourAddr;
			}
		
		}
		
		
		myOutputStream<<endl;
	}
	myOutputStream.close();
}

//4. Print graph Info
void Graph::printGraphInfo(){
	int maxDegree=0;

	
	for(int index=0;index<vertices.size();index++){
		Node* headNodePtr= vertices[index];
		int degree=0;

		if(headNodePtr!=NULL){
			Node* node= headNodePtr->neighbourAddr;

			while(node!=NULL){
				degree++;
				node=node->neighbourAddr;
			}

			if(degree>maxDegree){
				maxDegree=degree;
			}
		}

	}

	cout<< "Number of nodes:" << numberOfVertices<<endl;
	cout<< "Number of Edges:" << numberOfEdges <<endl;
	cout <<"Maximum degree is: "<< maxDegree<<endl;

}

//5. Get the number of neigbours for each vertice
int Graph::getNumNeighbors(int verticeIndex){
	int noOfNeighbors=0;
	Node* headNodePtr= vertices[verticeIndex];

	if(headNodePtr!=NULL){
		Node* node= headNodePtr->neighbourAddr;

		while(node!=NULL){
			noOfNeighbors++;
			node=node->neighbourAddr;
		}
	}

	return noOfNeighbors;
}

//6. Get the number of nodes in the graph
int Graph::getNumVertices(){
	return numberOfVertices;
}

void run(string edgeListFileName, string adjListFileName) {
	Graph g= Graph();
	g.loadGraph(edgeListFileName);
	g.dumpGraph(adjListFileName);
	g.printGraphInfo();

	cout << "Number of neighbors for specified vertice is: " <<g.getNumNeighbors(2)<<endl;
	cout << "Number of nodes in the graph are: "<<g.getNumVertices()<<endl; 
}




//*****************************************************************************


// The main will be removed for testing, do not add any code in the main function 

int main(int argc, char** argv) {
	run(argv[1], argv[2]);
	return 0;	

}

