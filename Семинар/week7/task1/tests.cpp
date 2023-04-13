#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "word.h"
#include  "Dictionary.h"


TEST_SUITE("Word class tests"){
    TEST_SUITE("Init - tests"){
        TEST_CASE("word - test"){
            Word word;
            word.init("word", "description");
            CHECK_FALSE(word.getWord() == nullptr);
        }

        TEST_CASE("description - test"){
            Word word;
            word.init("word", "description");
            CHECK_FALSE(word.getDescription() == nullptr);
        }
    }

    TEST_CASE("Operator = - test"){
        Word w1, w2;
        w1.init("w1", "d1");
        w2.init("w2", "d2");
        w2 = w1;
        CHECK_EQ( strcmp(w1.getWord(), w2.getWord()), 0);
    }

    // // to try this case make function: deleteDynamic() public
    // TEST_SUITE("Deallocation - tests"){
    //     TEST_CASE("word delete - test"){
    //         Word word;
    //         word.init("word", "description");
    //         word.deleteDynamic();
    //         CHECK_FALSE(word.getWord() != nullptr);
    //     }
    // }
}

TEST_SUITE("Dictionary class tests"){
    
    TEST_CASE("init - test"){
        Word w1, w2, w3;
        w1.init("w1", "d1");
        w2.init("w2", "d2");
        w3.init("w3", "d3");
        Word* words = new (std::nothrow) Word[3];
        Dictionary dict;
        dict.init(words, 3);
        CHECK_EQ(dict.getSize(), 3);
        delete[] words;
    }

    TEST_SUITE("Geters - tests"){
        TEST_CASE("getSize - first test"){
            Dictionary dict;
            CHECK_EQ(dict.getSize(), 0);
        }

        TEST_CASE("getSize - second test"){
            Dictionary dict;
            Word w1;
            w1.init("w1", "d1");
            dict.add(w1);
            CHECK_EQ(dict.getSize(), 1);
        }
    }
    
    TEST_CASE("add - test"){
        Dictionary dict;
        Word w1;
        w1.init("w1", "d1");
        dict.add(w1);
        CHECK_EQ(dict.getSize(), 1);
    }

    TEST_CASE("remove - test"){
        Dictionary dict;
        Word w1;
        w1.init("w1", "d1");
        dict.add(w1);
        dict.remove(w1.getWord());
        CHECK_EQ(dict.getSize(), 0);
    }

    TEST_CASE("find meaning - test"){
        Dictionary dict;
        Word w1, w2;

        w1.init("w1", "d1");
        w2.init("w2", "d2");

        dict.add(w1);
        dict.add(w2);

        CHECK_EQ(dict.findMeaning(w2.getWord()), w2.getDescription());
    }

    TEST_CASE("get by index - test"){
        Dictionary dict;
        Word w1, w2;

        w1.init("w1", "d1");
        w2.init("w2", "d2");

        dict.add(w1);
        dict.add(w2);

        CHECK_EQ(dict.getByIndex(1), w2.getDescription());
    }
}