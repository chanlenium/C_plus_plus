/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BASKET_H	// header guards
#define SDDS_BASKET_H

namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket
    {
        int m_cnt;
        double m_price;
        Fruit* m_fruits;
    public:
        Basket();                           // constructor with ono argument
        Basket(const Fruit*, int, double);  // constructor with 3 arguments
        Basket(const Basket&);              // copy constructor
        Basket& operator=(const Basket&);   // assignment
        ~Basket();                          // deconstructor
        void setPrice(double price);    
        operator bool() const {
            return m_cnt > 0;
        }
        Basket& operator +=(const Fruit&);
        friend std::ostream& operator<<(std::ostream& os, const Basket&);

        void clearmemory();
        void setEmpty();
        void init(const Basket&);
    };
}
#endif