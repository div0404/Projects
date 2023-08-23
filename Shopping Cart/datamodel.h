#include<string>
#include<unordered_map>
using namespace std;

//forward declaration
class Item;
class Cart;


class Product{
    int id;
    string name;
    int price;

    public:
    Product(){

    }
    Product(int u_id,string name,int price){
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName(){
        return name + ": Rs. " + to_string(price);
    }

    string getSortName(){
        return name.substr(0,1);
    }

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int Quantity;
    
    public:
    Item(){}
    //initialisation using initialisation list
    Item(Product p,int q):product(p),Quantity(q){}

    int getPrice(){
        return Quantity * product.price;
    }

    string itemInfo(){
        return to_string(Quantity) + " x " + product.name + ": Rs. " + to_string(Quantity * product.price) + '\n'; 
    }

    friend class Cart;
};

class Cart{
    //collection of items
    unordered_map<int,Item> items;

    public:

    void addProduct(Product product){
        if(items.count(product.id) == 0){
            //adding first time
            Item newItem(product,1);
            items[product.id] = newItem;
        }
        else{
            items[product.id].Quantity += 1;
        }
    }
    
    int getTotal(){
        int total = 0;
        for(auto itemPair : items){
            auto item = itemPair.second;
            total += item.getPrice();
        }
        return total;
    }
    string viewCart(){
        if(items.empty()){
            return "Cart is empty!";
        }

        string itemisedList;
        int cartTotal = getTotal();

        for(auto itemPair : items){
            auto item = itemPair.second;
            itemisedList.append(item.itemInfo());
        }
        return itemisedList + "\n Total amount : Rs. " + to_string(cartTotal) + '\n';
    }

    bool isEmpty(){
        return items.empty();
    }
};