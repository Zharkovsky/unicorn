#include <iostream>
#include "../CONSTANTS.cpp"
#include "../functions.cpp"
using namespace std;

void enterMatr(double ***firstMatrix, int &line1, int &column1, double ***secondMatrix, int &line2, int &column2)
{
	cout << ENTER_COMMAND << endl; 
	cout << YOUR_MATRIX << endl << RANDOM_MATRIX << endl;
	
	int command = 0;  //i is command
	
	string stringForInput; //for input
    cin >> stringForInput;
    stoi (stringForInput, command);
	
	switch(command)
	{
		case YOUR_MATRIX_FILL: {
			
			cout << ENTER_AMOUNT;
			cin >> stringForInput;
            stoi (stringForInput, command);
            
            switch(command)
            {
            	case oneMatr: {
           		 	cout << ENTER_SIZE;
            		cin >> stringForInput; 
					stoi (stringForInput, line1);
    	        	cin >> stringForInput; 
					stoi (stringForInput, column1);
                
            		*firstMatrix = newMatrix (line1, column1);
            		assert (*firstMatrix != NULL);
            	
    	    	    cout << ENTER_MATRIX;
    	        	for (int i = 0; i < line1; ++i)
    		        	for (int j = 0; j < column1; ++j)
    		        	{
    			        	cin >> stringForInput;
    			        	stod (stringForInput, (*firstMatrix)[i][j]);
    		        	}
            		
					break;
				}
				case twoMatr: {
    	            cout << ENTER_SIZE << FIRST_MATRIX;
            	    cin >> stringForInput; 
				    stoi (stringForInput, line1);
    	        	cin >> stringForInput; 
					stoi (stringForInput, column1);
				
            		*firstMatrix = newMatrix (line1, column1);
            		assert (*firstMatrix != NULL);
	
            		cout << ENTER_MATRIX;
            		for (int i = 0; i < line1; ++i)
    		    	    for (int j = 0; j < column1; ++j)
    		        	{
    			    	    cin >> stringForInput;
    			    	    stod (stringForInput, (*firstMatrix)[i][j]);
    		        	}
    		        
            		cout << ENTER_SIZE << SECOND_MATRIX;
            		cin >> stringForInput; 
					stoi(stringForInput, line2);
    	        	cin >> stringForInput; 
					stoi (stringForInput, column2);
                
	        		*secondMatrix = newMatrix (line2, column2);
	        		assert (*secondMatrix != NULL);
	        	
    	        	cout << ENTER_MATRIX;
    	        	for (int i = 0; i < line2; ++i)
            			for (int j = 0; j < column2; ++j)
    	        		{
    			        	cin >> stringForInput;
    			        	stod (stringForInput, (*secondMatrix)[i][j]);
    		        	}
					
					break;
				}
			}
            
			break;
		}
		
		case RANDOM_MATRIX_FILL: {
			
		    cout << ENTER_SIZE << FIRST_MATRIX <<endl;
		    cin >> stringForInput;
            stoi (stringForInput, line1);
            cin >> stringForInput;
            stoi (stringForInput, column1);
	        cout << ENTER_SIZE << SECOND_MATRIX <<endl;
	        cin >> stringForInput;
            stoi (stringForInput, line2);
            cin >> stringForInput;
            stoi (stringForInput, column2);
	    
		    *firstMatrix = newMatrix(line1,column1);
		    *secondMatrix = newMatrix(line2,column2);	
		
		    Random(*firstMatrix,line1,column1);
		    Random(*secondMatrix,line2,column2);
		    cout << FIRST_MATRIX << endl;
	    	show(*firstMatrix,line1,column1);
		    cout << SECOND_MATRIX << endl;
		    show(*secondMatrix,line2,column2);
		    
			break;
		}
		default: {
			cout << FALSE_COMMAND;
			enterMatr(firstMatrix, line1, column1, secondMatrix, line2, column2);
			break;
		}
	}
}
