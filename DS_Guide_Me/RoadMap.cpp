#include "RoadMap.h"

RoadMap::RoadMap()
{
	/*
	 4
Cairo - Giza Metro 30 Bus 60 Uber 230
Dahab - Giza Bus 500 Microbus 345
Cairo - BeniSuef Microbus 20 Bus 15
Asyut - Cairo Train 250 Bus 450 
	*/

	int num; cin >> num;
	cin.ignore();

	while (num--)
	{
		string line,source,destination,strPrice;
		Tranporation trans;

		getline(cin, line);       // read the whole line
		istringstream iss(line);  


		getline(iss, source, ' ');  // read source

		getline(iss, line, ' ');  // to pass '-'




		getline(iss, destination, ' '); // read destination


		// now we read the list of transportations && push 

		while (getline(iss, trans.vechile, ' ')) {
			
			getline(iss, strPrice, ' ');
			trans.price = stod(strPrice);

			// finally we add it.


			trans.destination = destination;
			map[source].push_back(trans);

			trans.destination = source;
			map[destination].push_back(trans);

		}

	}

	/*
	* 
	* For printing the map if needed
	* 
	cout << map.size() << endl;

	for (unordered_map<string, vector <Tranporation>>::iterator start = map.begin(); start != map.end(); start++)
	{
		cout << start->first << endl;

		for (int i = 0; i < start->second.size(); i++)
		{
			cout << start->second[i].destination << " " << start->second[i].vechile << " "
				<< start->second[i].price << "// ";
		}
		cout << endl;

	}

	*/

}


bool RoadMap::isComplete()
{
	stack<string> explore;
	unordered_set<string> visited;

	explore.push(map.begin()->first);
	
	while (!explore.empty())
	{

		string curr_city = explore.top();
		explore.pop();

		if (visited.find(curr_city) == visited.end()) {

			visited.insert(curr_city);

			//cout << curr_city << endl;

			for (vector <Tranporation>::iterator start = map[curr_city].begin(); start != map[curr_city].end(); start++)
			{
				if (visited.find(start->destination) == visited.end())
				{
					explore.push(start->destination);
				}

			}
		}
	}

	//cout << visited.size() << endl;


	return (map.size()==visited.size());

}
