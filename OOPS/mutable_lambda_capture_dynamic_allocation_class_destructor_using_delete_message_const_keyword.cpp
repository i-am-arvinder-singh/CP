#include<bits/stdc++.h>

class Base
{
private:
    int a, b ;
    mutable int  cc=0 ;
    const int w = 5;
public:
    Base(int a, int b)
    {
        Base * const c = this;
        c->a = a;
        c->b = b;
    }
    void Show()
    {
        std::cout<<"The value of 'a' and 'b' are "<<a<<" "<<b<<std::endl;
    }
    void Show_w() const
    {
        cc++;
        std::cout<<"The value of 'w' is "<<w<<std::endl;
    }
    void Show_c() const
    {
        std::cout<<"The value of 'cc' is "<<cc<<std::endl;
    }

};
int main()
{
    Base * b = new Base(2,3);
    b->Show();
    int w = 0;
    auto p = [=] () mutable
    {
        w++;
        for(int i = 0; i<4;i++){
            std::cout<<"***** "<<std::endl;
            b->Show_w();
            b->Show_c();
        }
        std::cout<< " From inside the function p() ---->> " << w <<std::endl;
    };
    std::cout<<"Times executed p() is : "<< w <<std::endl;
    p();
    std::cout<<"Times executed p() is : "<< w <<std::endl;
}
