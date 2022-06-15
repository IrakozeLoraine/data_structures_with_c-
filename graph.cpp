#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Edge {
	private:
		int destination_vertex_id;
		int weight;
	public:	
		Edge(){
		}
		
		Edge(int dest_id, int w){
			destination_vertex_id = dest_id;
			weight = w;
		}
		
		void setEdgeValues(int dest_id, int w){
			destination_vertex_id = dest_id;
			weight = w;
		}

		void setWeight(int w){
			weight = w;
		}

		int getWeight(){
			return weight;
		}

		int getDestinationVertexId(){
			return destination_vertex_id;
		}
};

class Vertex {
	int state_id;
	string state_name;
		
	public:
		list<Edge> edgeList;
		Vertex(){
			state_id = 0;
			state_name = "";
		}
		
		Vertex(int id, string name){
			state_id = id;
			state_name = name;
		}
		
		void setStateId(int sid){
			state_id = sid;
		}
		
		void setStateName(string sname){
			state_name = sname;
		}

		void setEdgeList(list<Edge> edges){
			edgeList = edges;
		}
		
		int getStateId(){
			return state_id;
		}
		
		string getStateName(){
			return state_name;
		}
		
		list<Edge> getEdgeList(){
			return edgeList;
		}
		
		void printEdgeList(){
			cout<<"[";
			for(auto i = edgeList.begin(); i!=edgeList.end(); i++){
				cout<<i->getDestinationVertexId()<<"("<<i->getWeight()<<")-->";
			}
			cout<<"]"<<endl;
		}
		
};

class Graph {
	vector<Vertex> vertices;
	
	public:
		void addVertex(Vertex newVertex){
			bool check = checkIfVertexExistById(newVertex.getStateId());
			
			if(check==true){
				cout<<"Vertex already exist";
			} else {
				vertices.push_back(newVertex);
				cout<<"New Vertex added";
			}
		}
		
		bool checkIfVertexExistById(int vid){
			for(int i=0; i<vertices.size(); i++){
				if(vertices.at(i).getStateId()==vid)
					return true;
			}
			return false;
		}
	
		void printGraph(){
			cout<<"[";
			for(int i=0; i<vertices.size(); i++){
				Vertex temp;
				temp = vertices.at(i);
				cout<<temp.getStateName()<<"("<<temp.getStateId()<<")-->";
				temp.printEdgeList();
			}
			cout<<"]"<<endl;
		}
		
		Vertex getVertexById(int vid){
			Vertex temp;
			for(int i=0; i<vertices.size(); i++){
				temp = vertices.at(i);
				if(temp.getStateId()==vid){
					return temp;
				}
			}
			return temp;
		}
		
		bool checkIfEdgeExistById(int source, int destination){
			Vertex v = getVertexById(source);
			list<Edge> e = v.getEdgeList();
			
			for(auto i=e.begin(); i!=e.end(); i++){
				if(i->getDestinationVertexId()==destination){
					return true;
				}
			}
			return false;
		}
		
		void addEdgeById(int source, int destination, int weight){
			bool check1 = checkIfVertexExistById(source);
			bool check2 = checkIfVertexExistById(destination);
			
			if(check1 && check2){
				bool check3 = checkIfEdgeExistById(source, destination);
				if(check3){
					cout<<"Edge already exists."<<endl;
				} else {
					for(int i=0; i<vertices.size(); i++){
						if(vertices.at(i).getStateId() == source){
							Edge e(destination, weight);
							vertices.at(i).edgeList.push_back(e);
						} else if(vertices.at(i).getStateId()==destination){
							Edge e(source, weight);
							vertices.at(i).edgeList.push_back(e);
						}
					}
					cout<<"Edge added successfully"<<endl;
				}
			} else {
				cout<<"Invalid Vertex Id entered."<<endl;
			}
		}
		
		void updateEdgeById(int source, int destination, int newWeight){
			bool check = checkIfEdgeExistById(source, destination);
			if(check){
				for(int i=0; i<vertices.size();i++){
					if(vertices.at(i).getStateId()== source){
						for(auto j=vertices.at(i).edgeList.begin(); j!=vertices.at(i).edgeList.end(); j++){
							if(j->getDestinationVertexId()==destination){
								j->setWeight(newWeight);
								break;
							}
						}
					} else if(vertices.at(i).getStateId()==destination){
						for(auto j=vertices.at(i).edgeList.begin(); j!=vertices.at(i).edgeList.end(); j++){
							if(j->getDestinationVertexId()==source){
								j->setWeight(newWeight);
								break;
							}
						}
					}
				}
				cout<<"Edge weight updated successfully"<<endl;
			} else {
				cout<<"Edge does not exist"<<endl;
			}
		}

		void deleteEdgeById(int source, int destination){
			bool check = checkIfEdgeExistById(source, destination);
			if(check){
				for(int i=0; i<vertices.size(); i++){
					if(vertices.at(i).getStateId()==source){
						for(auto j=vertices.at(i).edgeList.begin(); j!=vertices.at(i).edgeList.end();j++){
							if(j->getDestinationVertexId()==destination){
								vertices.at(i).edgeList.erase(j);
								break;
							}
						}
					} else if(vertices.at(i).getStateId()==destination){
						for(auto j=vertices.at(i).edgeList.begin(); j!=vertices.at(i).edgeList.end(); j++){
							if(j->getDestinationVertexId()==source){
								vertices.at(i).edgeList.erase(j);
								break;
							}
						}
					}
				}
				cout<<"Edge deleted successfully"<<endl;
			} else {
				cout<<"Edge does not exist"<<endl;
			}
		}
};

int main(){
	int option, id1, id2, weight;
	string sname;
	Graph g; 
	Vertex v1;
	
	do{
		cout<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Add Vertex"<<endl;
		cout<<"2. Update Vertex"<<endl;
		cout<<"3. Delete Vertex"<<endl;
		cout<<"4. Add Edge"<<endl;
		cout<<"5. Update Edge"<<endl;
		cout<<"6. Delete Edge"<<endl;
		cout<<"7. Check if 2 vertices are neighbours"<<endl;
		cout<<"8. Print all neighbors of a vertex"<<endl;
		cout<<"9. Print Graph"<<endl;
		cout<<"10. Clear Screen"<<endl;
		cout<<"0. Exit program"<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"Add vertex operation - "<<endl;
				cout<<"Enter State ID: ";
				cin>>id1;
				cout<<"Enter State Name: ";
				cin>>sname;
				v1.setStateId(id1);
				v1.setStateName(sname);
				g.addVertex(v1);
				break;
			case 2:
				cout<<"Update vertex operation - "<<endl;
				break;
			case 3:
				cout<<"Delete vertex operation - "<<endl;
				break;
			case 4:
				cout<<"Add Edge Operation - "<<endl;
				cout<<"Enter ID of Source Vertex: ";
				cin>>id1;
				cout<<"Enter ID of Destination Vertex: ";
				cin>>id2;
				cout<<"Enter weight of edge: ";
				cin>>weight;
				g.addEdgeById(id1, id2, weight);
				break;
			case 5:
				cout<<"Update Edge Operation - "<<endl;
				cout<<"Enter Id of source vertex: ";
				cin>>id1;
				cout<<"Enter id of destination vertex: ";
				cin>>id2;
				cout<<"Enter updated weight of edge: ";
				cin>>weight;
				g.updateEdgeById(id1, id2, weight);
				break;
			case 6:
				cout<<"Delete Edge Operation - "<<endl;
				cout<<"Enter Id of source vertex: ";
				cin>>id1;
				cout<<"Enter id of destination vertex: ";
				cin>>id2;
				g.deleteEdgeById(id1, id2);
				break;
			case 7:
				cout<<"Check if 2 Vertices are neighbors - "<<endl;
				break;
			case 8:
				cout<<"Print all neighbors of a vertex - "<<endl;
				break;
			case 9:
				cout<<"Print Graph Operation - "<<endl;
				g.printGraph();
				break;
			case 10:
				system("cls");
				break;
			default:
				cout<<"Invalid option"<<endl;
		}
		cout<<endl;
	}while(option!=0);
	
	return 0;
}