#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>

class Transaction{
    private:
        std::string name;
        std::string type;
        int value;

    public:
        //Constructor
        Transaction(std::string name = "Unnamed", std::string type = "Unknown", int value = 0);
        
        //Destructor
        ~Transaction();

        //Accessors
        inline const std::string& getName() const { return this->name; };
        inline const std::string& getType() const { return this->type; };
        inline const int& getValue() const { return this->value; };
            /*
             * Having the accessors as references (&)
             * would normaly mean we could alter the private variables.
             * However, since they are const, it's not possible
             * to alter the variables through them.
             * Tsumari, the reference serves the purpose of optimizing
             * the code (by avoiding unecessary copies), while
             * the const protects the variables from changes.
             */

        //Modifiers
        inline std::string setName(std::string name){ this->name = name; };
        inline std::string setType(std::string type){ this->type = type; };
        inline int setValue(int value){ this->value = value; };
            /*
             * Frank Gleeson, a quora.com user,
             * explains that the only advantage of passing by reference,
             * in a setter, emerges when we are passing something
             * that is bigger than a pointer (8 bytes in 64bit machines)
             */
        
        //Functions
        std::string toString();
};

#endif