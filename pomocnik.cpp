//
// Created by maciek on 16.12.2020.
//

int main() {

    std::vector<Product*> prod;

    Product* ptr;
    ProductWeight pw;
    ProductPieces pp;
    ProductLiters pl;

    ptr = &pw;
    prod.push_back(ptr->createNew());
    ptr = &pp;
    prod.push_back(ptr->createNew());
    ptr = &pl;
    prod.push_back(ptr->createNew());


    prod[0]->printDetails();
    prod[1]->printDetails();
    prod[2]->printDetails();

    for(int i = 0; i < prod.size(); i++)
        delete prod[i];
}