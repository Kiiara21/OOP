#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Menu.h" 

TEST_SUITE ("MenuItem tests"){
    TEST_CASE("Get price test1"){
        MenuItem mi;
        CHECK_EQ(mi.getPrice(), 0);
    }

    TEST_CASE("Get price test2"){
        MenuItem mi("napitka", "bezalkoholna", 2, 2.2);
        CHECK_EQ(mi.getPrice(), 2.2);
    }
}

TEST_SUITE("Alcohol tests"){
    TEST_CASE("get procent test1"){
        Alcohol alcohol(12, "napitka", "bezalkoholna", 2, 2.2, "glass");
        CHECK_EQ(alcohol.getProcent(), 12);
    }

    TEST_CASE("get price test1"){
        Alcohol alcohol(12, "napitka", "bezalkoholna", 2, 2.2, "glass");
        CHECK_EQ(alcohol.getPrice(), 2.2);
    }

    TEST_CASE("get name test1"){
        Alcohol alcohol(12, "napitka", "bezalkoholna", 2, 2.2, "glass");
        CHECK_EQ(alcohol.getName(), "napitka");
    }

    TEST_CASE("get description test1"){
        Alcohol alcohol(12, "napitka", "bezalkoholna", 2, 2.2, "glass");
        CHECK_EQ(alcohol.getDescription(), "bezalkoholna");
    }

    TEST_CASE("get quantity test1"){
        Alcohol alcohol(12, "napitka", "bezalkoholna", 2, 2.2, "glass");
        CHECK_EQ(alcohol.getQuantity(), 2);
    }
}

TEST_SUITE("Menu tests"){
    TEST_CASE("add menu item"){
        Menu menu;
        menu.addMenuItem("napitka", "bezalkoholna", 2, 2.2);
        CHECK_EQ(menu.getNumberOfItems(), 1);
    }

    TEST_CASE("add drink"){
        Menu menu;
        Drink drink("glass", "mochito", "coctail", 1, 30);
        CHECK_EQ(menu.getNumberOfItems(), 0);
        menu.addDrink(drink);
        CHECK_EQ(menu.getNumberOfItems(), 1);
    }

    TEST_CASE("add alcohol"){
        Menu menu;
        Alcohol alcohol(12, "mochito", "coctail", 1, 30, "glass");
        CHECK_EQ(menu.getNumberOfItems(), 0);
        menu.addDrink(alcohol);
        CHECK_EQ(menu.getNumberOfItems(), 1);
    }

    TEST_CASE("add food"){
        Menu menu;
        Food food(1, 0, "sandwich", "big nonvegan sandwich", 2, 20);
        CHECK_EQ(menu.getNumberOfItems(), 0);
        menu.addFood(food);
        CHECK_EQ(menu.getNumberOfItems(), 1);
    }

    TEST_CASE("get cheaper item"){
        Menu menu;
        Alcohol alcohol(12, "mochito", "coctail", 1, 30, "glass");
        Food food1(1, 0, "sandwich1", "big nonvegan sandwich", 2, 20);
        Food food2(1, 0, "sandwich2", "big nonvegan sandwich", 2, 21);
        Food food3(1, 0, "sandwich3", "big nonvegan sandwich", 2, 22);
        menu.addAlcohol(alcohol);
        menu.addFood(food1);
        menu.addFood(food2);
        menu.addFood(food3);
        MenuItem cheaperItem = menu.cheaperItem();

        CHECK_EQ(cheaperItem.getName(), "sandwich1");
    }

    TEST_CASE("get number of items"){
        Menu menu;
        Alcohol alcohol(12, "mochito", "coctail", 1, 30, "glass");
        Food food1(1, 0, "sandwich1", "big nonvegan sandwich", 2, 20);
        Food food2(1, 0, "sandwich2", "big nonvegan sandwich", 2, 21);
        Food food3(1, 0, "sandwich3", "big nonvegan sandwich", 2, 22);
        menu.addAlcohol(alcohol);
        menu.addFood(food1);
        menu.addFood(food2);
        menu.addFood(food3);
        int numberOfItems = menu.getNumberOfItems();

        CHECK_EQ(numberOfItems, 4);
    }

    TEST_CASE("get number of non alcohol drinks"){
        Menu menu;
        Alcohol alcohol1(12, "mochito", "coctail", 1, 30, "glass");
        Food food1(1, 0, "sandwich1", "big nonvegan sandwich", 2, 20);
        Food food2(1, 0, "sandwich2", "big nonvegan sandwich", 2, 21);
        Food food3(1, 0, "sandwich3", "big nonvegan sandwich", 2, 22);
        menu.addAlcohol(alcohol1);
        menu.addFood(food1);
        menu.addFood(food2);
        menu.addFood(food3);
        int numberOfNonAlcoholDrinks = menu.numberOfNonAlcoholDrinks();
        CHECK_EQ(numberOfNonAlcoholDrinks, 0);
        Alcohol alcohol2(0, "mochito", "coctail", 1, 30, "glass");
        menu.addAlcohol(alcohol2);
        numberOfNonAlcoholDrinks = menu.numberOfNonAlcoholDrinks();
        CHECK_EQ(numberOfNonAlcoholDrinks, 1);

    }




}

