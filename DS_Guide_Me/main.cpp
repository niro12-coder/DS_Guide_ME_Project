#include<iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Edge {
private:
    string destination;
    string transportationMethod;
    int price;
public:
    Edge(string dest, string trans, int p) {
        destination = dest;
        transportationMethod = trans;
        price = p;
    }
    Edge() {
        destination = "";
        transportationMethod = "";
        price = 0;
    }
    string getDestination() {
        return destination;
    }
    string getTransportationMethod() {
        return transportationMethod;
    }
    int getPrice() {
        return price;
    }
    void setPrice(int p) {
        price = p;
    }
};

class Graph {
private:
    unordered_map<string, vector<Edge>> adjList;
    unordered_map<string, vector<Edge>>::iterator it;
public:
    void addEdge(string src, string dest, string trans, int price) {
        // undirected graph
        adjList[src].push_back(Edge(dest, trans, price));
        adjList[dest].push_back(Edge(src, trans, price));
    }

    void addTransportation(string src, string dest, string trans, int price) {
        for (Edge edge : adjList[src]) { // checks if the edge already exists
            if (ignoreCaseInsensitive(edge.getDestination(), dest) && ignoreCaseInsensitive(edge.getTransportationMethod(),trans)) {
                cout << "Transportation already exists!\n";
                return;
            }
        }
        addEdge(src, dest, trans, price); // If the edge doesn't exist -> add new edge
        cout << "New Transportation has been added!\n";
    }

    void addInitialEdges(Graph& graph) {
        // original map
        graph.addEdge("Asyut", "Cairo", "Trian", 250);
        graph.addEdge("Asyut", "Cairo", "Bus", 450);
        graph.addEdge("Cairo", "BeniSuef", "Microbus", 20);
        graph.addEdge("Cairo", "BeniSuef", "Bus", 15);
        graph.addEdge("BeniSuef", "Dahab", "Microbus", 200);
        graph.addEdge("BeniSuef", "Dahab", "Bus", 315);
        graph.addEdge("Dahab", "Giza", "Bus", 500);
        graph.addEdge("Dahab", "Giza", "Microbus", 345);
        graph.addEdge("Giza", "Cairo", "Metro", 30);
        graph.addEdge("Giza", "Cairo", "Bus", 60);
        graph.addEdge("Giza", "Cairo", "Uber", 230);
    }

    void addTransportation(Graph& graph, string* src, string* dest, string* trans, int* price) {
        graph.addTransportation(*src, *dest, *trans, *price);
    }

    void displayGraph() {
        cout << "Main map: \n";
        for (it = adjList.begin(); it != adjList.end(); ++it) {
            cout << "City: " << it->first << " -> \n";
            for (int i = 0; i < it->second.size(); ++i) {
                cout << "(" << it->second[i].getDestination() << ", " << it->second[i].getTransportationMethod() << ", " << it->second[i].getPrice() << ") ";
            }
            cout << endl;
            cout << endl;
        }
    }

    void Add(Graph& graph) {
        displayGraph();

        string c = "";
        do {
            string src, dest, trans;
            int price;

            cout << "Enter the source city: ";
            getline(cin, src);

            cout << "Enter the destination city: ";
            getline(cin, dest);

            //string srcLower = src;
            //string destLower = dest;
            //transform(srcLower.begin(), srcLower.end(), srcLower.begin(), tolower);
            //transform(destLower.begin(), destLower.end(), destLower.begin(), tolower);

            if (cityExists(toLower(src)) && cityExists(toLower(dest))) {
                cout << "Enter the transportation method: ";
                getline(cin, trans);

                cout << "Enter the price: ";
                cin >> price;

                addTransportation(graph, &src, &dest, &trans, &price);
                displayGraph();
            }

            else {
                cout << "The city does not exist in the list.\n";
            }

            cout << "Do you want to add a new transportation? \n";
            cin >> c;
            cin.ignore(); // prevents a new line encounter

        } while (c == "y" || c == "Y");
    }

    bool cityExists(string s) {
        vector<string> cities = { "Asyut", "Cairo", "BeniSuef", "Dahab", "Giza" };  // List of cities

        for (char& c : s) {
            c = tolower(c);
        }

        for (string& city : cities) {
            for (char& c : city) {
                c = tolower(c);
            }

            if (city == s) {
                return true; // City exists
            }
        }

        return false; // City does not exist
    }

    bool ignoreCaseInsensitive(string str1, string str2) { // compares two strings
        if (str1.length() != str2.length()) {
            return false; // If lengths are different, strings are not equal
        }

        for (int i = 0; i < str1.length(); ++i) {
            if (tolower(str1[i]) != tolower(str2[i])) {
                return false; // If characters are different, strings are not equal
            }
        }

        return true; // Strings are equal
    }

    string toLower(string s) {
        string result = s; 

        for (char& c : result) {
            c = tolower(c);
        }
        return result; 
    }

};
int main()
{
    Graph graph;
    graph.addInitialEdges(graph);
    graph.Add(graph);
 
	return 0;
}