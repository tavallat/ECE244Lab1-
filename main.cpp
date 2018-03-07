#include <cstdlib>

#include <iostream>

#include <sstream>

#include <string>

#include <iomanip>

#define MAX_NODE_NUMBER 5000


using namespace std;

void insertRCommand(string Rname, float Rvalue, int node1, int node2, string extra) {
    
    //this function deals with the cases where Rname is all, Rvalue is negative,
    //node1 and node2 are equal, node1 and node2 are out of range, too many and
    //too few arguments as well as printing the output if everything is done right
    //ensures the precision for the value is set to 2
    
    cout << setprecision(2) << fixed;
    
    if (Rname == "all")
        
        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
    
    
    else if (Rvalue < 0) //deals with the value of the resistance being negative
        
        cout << "Error: negative resistance" << endl;
    
    
    
    //if node 1 and node 2 were the same
    
    else if (node1 == node2)
        
        cout << "Error: both terminals of resistor connect to node " << node1
        
        << endl;
    
    //if the value of the nodes are too high
    
    else if (node1 > MAX_NODE_NUMBER || node1 < 0)
        
        cout << "Error: node " << node1 <<
        
        " is out of permitted range 0-5000" << endl;
    
    
    
    else if (node2 > MAX_NODE_NUMBER || node2 < 0)
        
        cout << "Error: node " << node2 <<
        
        " is out of permitted range 0-5000" << endl;
    
    
   //making sure i have enough arguments
    else if (Rname == "Rname" || Rvalue == 1000000000 || node1 == 4999 || node2 == 4998)
        
        cout << "Error: too few arguments" << endl;
    
    
    
    else if (extra != "extra")
        
        cout << "Error: too many arguments" << endl;
    
    // the program will get here only if everything has been successful
    
    else cout << "Inserted: resistor " << Rname << " " << Rvalue << " Ohms " <<
        
        node1 << " -> " << node2 << endl;
    return;
    
}

void modifyCommand(string Rname, float newvalue, string extra) {
    
    //this function takes care of negative resistance, too many and too few
    //it also generates the output if all is good
    
    cout << setprecision(2) << fixed;
    
    if (newvalue < 0)
        
        cout << "Error: negative resistance" << endl;
    
    
    else if (Rname == "all")
        
        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
    
    
    
    else if (Rname == "Rname" || newvalue == 99999)
        
        cout << "Error: too few arguments" << endl;
    
    
    
    else if (extra != "extra")
        
        cout << "Error: too many arguments" << endl;
    
    
    
    else cout << "Modified: resistor " << Rname << " to " << newvalue << " Ohms"
        
        << endl;
    
    return;
    
}

void deleteRCommand(string Rname, string extra) {
    
    //this function deals with the output for the command
    
    if (Rname == "all")
        
        cout << "Deleted: all resistors" << endl;
    else
        
        cout << "Deleted: resistor " << Rname << endl;
    
    return;
    
}

void printRCommand(string Rname, string extra) {
    
    //this function deals with too many, too few as well as the output
    
    if (Rname == "all")
        
        cout << "Print: all resistors" << endl;
    
    else if (Rname == "Rname")
        
        cout << "Error: too few arguments" << endl;
    
    else if (extra != "extra")
        
        cout << "Error: too many arguments" << endl;
    
    else
        
        cout << "Print: resistor " << Rname << endl;
    
    return;
    
}

void printNodeCommand(int nodevalue, string extra) {
    
    //this function deals with too few, too many, range and output
    
    //if (nodevalue == 4999)
        //cout << "Error: too few arguments" << endl;
    
     if (nodevalue > MAX_NODE_NUMBER || nodevalue < 0)
        
        cout << "Error: node " << nodevalue <<
        
        " is out of permitted range 0-5000" << endl;
    
    //else if (extra != "extra")
        //cout << "Error: too many arguments";
    
  //  else if (nodevalue == nodevalue && extra != "extra")
    //    cout << "Error: too many arguments";
    
    else cout << "Print: node " << nodevalue << endl;
    
    return;
    
}

void printRCommand(string Rname) {
    //this function deals with output of the command printR
    
    if (Rname == "all")
        cout << "Print: all resistors" << endl;
    else
        cout << "Print: resistor " << Rname << endl;
    return;
}






int main(int argc, char** argv) {
    
    string command, line, input;
    
    
    cout << "> ";
    getline(cin, line);
    
    while (!cin.eof()) {
        stringstream linestream(line);
        
        //command is retracted from line stream
        linestream >> command;
        //going through each command and applying what is needed
        
        //***** insertR COMMAND *****
        
        if (command == "insertR") {
            
            string Rname, extra;
            
            float Rvalue;
            
            int node1, node2;
            
            //initializing each variable
            
            Rname = "Rname";
            
            Rvalue = 1000000000;
            
            node1 = 4999;
            
            node2 = 4998;
            
            extra = "extra";
            
            linestream >> Rname;
            linestream >> Rvalue;
            linestream >> node1;
            //making sure the user doesnt enter decimal numbers
            char next;
            
            next = linestream.peek();
            
            
            if (next == '.' || next > 33) //this is to ensure the user dosent type a wrong character after
                cout << "Error: invalid argument" << endl;
            else {
                linestream >> node2;
                next = linestream.peek();
                if (next == '.' || next > 33 )
                    cout << "Error: invalid argument" << endl;
                
                else {
                    
                    linestream >> extra;
                    
                    if (Rvalue < 0) //negative resistance
                        
                        cout << "Error: negative resistance" << endl;
                    
                    
                    else if (linestream.fail() && !linestream.eof())
                        
                        cout << "Error: invalid argument" << endl; //if input is
                    //wrong
                    else
                        
                        insertRCommand(Rname, Rvalue, node1, node2, extra);
                    
                }
            }
        }
        
        
        //***** modifyR COMMAND *****
        
        else if (command == "modifyR") {
            
            string Rname, extra;
            
            float newvalue;
            
            Rname = "Rname"; //initialized value of newvalue
            
            newvalue = 99999; //initialized value of newvalue
            
            extra = "extra"; //initialized value of extra
            
            linestream >> Rname >> newvalue;
            
            char next;
            next = linestream.peek();
            if (next == '.' || next > 33)
                cout << "Error: invalid argument" << endl;
            
            else {
            linestream >> extra;
            
             if (linestream.fail() && !linestream.eof()) //if invalid argument
                
                
                cout << "Error: invalid argument" << endl;
            
            else
                
                modifyCommand(Rname, newvalue, extra);
            
            }}
        
        //***** deleteR COMMAND *****
        
        else if (command == "deleteR") {
            
            string Rname, extra;
            //initializing the values
            Rname = "Rname";
            extra = "extra";
            //get the input from stream
            
            linestream >> Rname >>extra;
            if (Rname == "Rname")
                cout << "Error: too few arguments" << endl;
            
            else if (extra != "extra")
                cout << "Error: too many arguments" << endl;
            
            
            else if (linestream.fail() && !linestream.eof())
                
                cout << "Error: invalid argument" << endl;
            else
                
                deleteRCommand(Rname, extra);
        }
        
        //***** printNode COMMAND *****
        
        else if (command == "printNode") {
            int nodevalue;
            string extra;
            nodevalue = 4999; //initialized value
            extra = "extra"; //initialized value
            linestream >> nodevalue;
            char nextchar;
            if (linestream.fail() & linestream.eof())
                cout << "Error: too few arguments" << endl;
            
            else if (linestream.fail()) {
                //clear the integer to see whats up
                linestream.clear();
                string badinput;
                linestream >> badinput;
                //i have to check if badinput is all or not
              //MY ALL BLOCK
                
                if (badinput == "all") {
                    //i have to check if they inputed extra or not
                    linestream >> extra;
                    if (extra != "extra")
                        cout << "Error: too many arguments" << endl;
                    else
                        cout << "Print: all nodes" << endl;
                    
                    // by now i have dealt with all
                } else
                    cout << "Error: invalid argument" << endl;
            } //now lets consider all cases where an integer input can go wrong
            else {
                nextchar = linestream.peek ();
                
                if (nextchar == '.' || nextchar > 33)
                cout <<"Error: invalid argument" << endl;
                
                else {
                        linestream >> extra;
                
                if (nodevalue < 0 || nodevalue > 5000)
                    cout << "Error: node " << nodevalue << " is out of permitted range 0-5000" << endl;
                else if (nodevalue == 4999)
                    cout << "Error: too few arguments" << endl;
                else if (nodevalue != 4999 && extra != "extra")
                    cout << "Error: too many arguments" << endl;
                else if (extra != extra)
                    cout << "Error: too many arguments" << endl;
                else
                printNodeCommand(nodevalue, extra);
            }
            }
        }//****** PRINTR COMMAND ***************
        
        else if (command == "printR") {
            
            string Rname, extra;
            
            //initializing the values
            
            Rname = "Rname";
            
            extra = "extra";
            
            //get the input from stream
            
            linestream >> Rname >> extra;
            
            if (linestream.fail() && !linestream.eof())
                
                cout << "Error: invalid argument" << endl;
            
            else
                
                printRCommand(Rname, extra);
        } else
            
            cout << "Error: invalid command" << endl;
        
        linestream.ignore(1000, '\n');
        
        command = "hehe...nottoday"; //this is to ensure if the user 
        //presses enter i dont get invalid command 
        
        cout << "> ";
        getline(cin, line);
    }
    return (0);
    
}
