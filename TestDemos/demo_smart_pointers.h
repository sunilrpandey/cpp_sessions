#pragma once
#include <iostream>
#include <memory>
using namespace std;
//after shared pointer(ptr5) .reset(), use_count of ptr5 would be zero but for other pointers it would be 
// reduced by only 1

namespace ns_smartptrs
{

    // what to do and not to do with shared pointer

    // dont use raw pointer to initialize shared pointer
    // in below code rp will be deleted twice 
    // int * rp = new int;
    // shared_ptr<int> outer_p(rp);{
    //     shared_ptr<int> inner_p(rp);
    // }

    // dont create shared_ptr from stack but from heap only.
    int counter = 1;
    class Dog
    {
    public:
        string name_;

        Dog(const string& str = "") :name_(str) {
            name_.append(to_string(counter++));
            cout << "\nBirth : " << name_.c_str() << std::endl;
        }
        Dog(const initializer_list<string>& vec_str) {
            name_ = *(vec_str.begin());
            Dog(name_);
            //name_.append(to_string(counter++));
            //cout << "init_list Birth : " << name_.c_str() << endl; 
        }
        ~Dog() {
            cout << "\nDeath : " << name_.c_str() << std::endl;
        }
        void bark() {
            cout << "I am " << name_.c_str() << endl;
        }
    };
    unique_ptr<Dog> getPtr(const std::string& dname, bool make_unique_flag = true)
    {
        if (make_unique_flag) {
            return make_unique<Dog>(dname);
        }

        unique_ptr<Dog> p(new Dog(dname));
        //p->bark();
        return p;
    }
    int demoUniquePtr()
    {
        // you can use new operator or make_unique to initialize
        bool use_make_unique = false;
        unique_ptr<Dog> p = getPtr("Smoky", use_make_unique);
        cout << endl << "p : " << p->name_;

        // assignments or copying transfers ownership
        unique_ptr<Dog> p2 = move(p);
        cout << endl << "p2  : " << p2->name_;
        if (!p) {
            cout << endl << "no more p" << endl;
        }

        unique_ptr<Dog> emptyPtr = nullptr;
        emptyPtr = move(p2);
        cout << "\nEmptyPtr got something : " << emptyPtr->name_;

        //reset deletes the resource underneath
        cout << endl << "See how NewDog replaces old one";
        emptyPtr.reset(new Dog("NewDog"));


        cout << "\n->->Demo : make unique <-<- ";
        auto dgPtr = make_unique<Dog>("Madebymakeunique");
        cout << "\n Name of this dog: " << dgPtr->name_ << endl;

        auto releasedFromDgPtr = dgPtr.release();
        cout << endl << "releasedFromDgPtr : " << releasedFromDgPtr->name_;

        delete releasedFromDgPtr;
        return 0;
    }
    shared_ptr<Dog> getSharedPtr(const std::string& str, bool use_make_shared = true)
    {
        if (use_make_shared)
            return make_shared<Dog>(str);

        shared_ptr<Dog> p(new Dog(str));
        return p;
    }

    void demo_with_int_ptr()//shared pointer assignments and ref count changes demo
    {
        std::shared_ptr<int> spi1(new int(15));
        cout << endl << spi1.use_count();

        std::shared_ptr<int> spi2 = spi1;
        std::shared_ptr<int> spi3 = spi2;
        cout << "\nmade 2 more instance, use count(should be 3) : " << spi3.use_count();

        std::shared_ptr<int> spi5 = std::make_shared<int>(30);
        std::shared_ptr<int> spi6 = spi5;
        cout << "\nmade 2 instance of int 30, use count(should be 2) : " << spi5.use_count();

        spi3 = spi5;
        cout << "\none ref of pre group will be decremented and ref of later group will be incremented, hence spi1(shd be 2) : " << spi1.use_count() \
            << " and spi6(should be 3) : " << spi6.use_count();

        cout << endl;
    }

    void demo_basic_funcs()
    {
        cout << "\n----- Basic Functions ----------";

        shared_ptr<Dog> spd1(new Dog("Smarty"));
        cout << "\nUse count : " << spd1.use_count();

        shared_ptr<Dog> spd2 = spd1;
        cout << "\nUse count should be 2 and is : " << spd1.use_count() << " - " << spd2.use_count();

        auto spd3 = getSharedPtr("SmartyV2");
        Dog* dg = spd3.get();
        if (spd3) {
            cout << "\nGet() gives access to raw pointer : " << spd3->name_;
        }
        else {
            cout << "\nGet() give up raw pointer : " << dg->name_;
        }

        cout << "\nusage count sp3 before assigning to spd4 : " << spd3.use_count();

        cout << "\n Assigning spd3 to spd4 " << endl;
        auto spd4(spd3);
        cout << "\n spd4 : use count : " << spd4.use_count() << " & spd3 : use count : " << spd3.use_count();
        cout << "\n Resetting spd4 " << endl;
        spd4.reset();
        cout << "\n after reset use count of spd3 :" << spd3.use_count() << " that of spd4 : " << spd4.use_count();

        cout << "\nname of spd3 before reset to Resetty : " << spd3->name_ << " and use count : " << spd3.use_count();
        spd3.reset(new Dog("Resetty"));
        cout << "\nname of spd3 after reset to Resetty : " << spd3->name_ << " and use count : " << spd3.use_count();

        spd4 = spd3;
        cout << "\nspd4, reassigned, use count of spd4 : " << spd4.use_count() << " & use count of spd3 : " << spd3.use_count();
        spd3 = nullptr;
        cout << "\nneed to check if assigning spd3 to null changes use_count of spd4(which should be yes) : " << spd4.use_count();

    }

    void demo_custom_deleter()
    {
        cout << endl << "Demo : Custom Deleter";
        //custom deleter for array object other wise it iwll not call [] delete
        {
            cout << "\nDeleting shared ptr for object array : ";
            shared_ptr<Dog[]> sp_arr(new Dog[3], [](Dog* p) { cout << "\nCustom Deleting..."; delete[] p; });
            sp_arr[0].bark();
            sp_arr[1].bark();
            sp_arr[2].bark();
        }

    }

    void demoUniquePointerToSharedPointer()
    {
        unique_ptr<Dog> up2 = make_unique<Dog>("Tommy");
        up2->bark();
        //up2.reset();
        //pObj = up1.get();

        //shared_ptr<Dog> sp = std::move(up2);
        // Unique() - Checks if* this is the only shared_ptr instance managing the current object, i.e.whether use_count() == 1.
        //cout << sp.unique() << "count : " << sp.use_count() << endl;
        //shared_ptr<Dog> sp2 = sp;
        //cout << sp.unique() << "count : " << sp.use_count() << endl;
        //cout << sp2.unique() << "count : " << sp2.use_count();


    }

    void demo_arrayUniquePtr()
    {
        cout << endl << "Demo : Array of unique Ptrs and mgmt";
        //custom deleter for array object other wise it iwll not call [] delete
        {
            cout << "\nCreation/Deletion of unique ptrs for object array : ";
            //unique_ptr<Dog[]> sp_arr(new Dog[3]);
            //unique_ptr<Dog[]> sp_arr(new Dog[3]{Dog("Dog1"),Dog("Dog2"),Dog("Dog3") });
            //auto sp_arr = std::make_unique<Dog[]>(3); // init like above wont work with make_unique

            auto sp_arr = std::unique_ptr<Dog[]>(new Dog[3]{ Dog("Dog1"),Dog("Dog2"),Dog("Dog3") });
            sp_arr[0].bark();
            sp_arr[1].bark();
            sp_arr[2].bark();
        }

    }

    void demo_arraySharedPtr()
    {
        //make_shared not supported for array
        
        std::shared_ptr<int[]> sp(new int[3] {2, 3, 4}); // cpp17
        std::shared_ptr<Dog[]> spd(new Dog[3] {Dog("Dog1"), Dog("Dog2"), Dog("Dog3") }); // cpp17
        for (int i = 0; i < 3; i++) {
            cout << sp[i] << "  ";
        }
        for (int i = 0; i < 3; i++) {
            spd[i].bark();
        }

    }

    void demo() {

        demo_arraySharedPtr();
        return;

        demoUniquePtr();
        demoUniquePointerToSharedPointer();
        demo_with_int_ptr();
        demo_basic_funcs();
        demo_custom_deleter();
        demo_arrayUniquePtr();

        
    }

}

