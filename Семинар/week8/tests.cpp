#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Library.h"

TEST_SUITE("Author tests"){

    TEST_CASE("Name getter"){
        Author author("kiara", "chobanova", 21, "kiarachobanova@abv.bg");
        CHECK_EQ("kiara", author.getName());
    }

    TEST_CASE("Last name getter"){
        Author author("kiara", "chobanova", 21, "kiarachobanova@abv.bg");
        CHECK_EQ("chobanova", author.getLastName());
    }

    TEST_CASE("Age getter"){
        Author author("kiara", "chobanova", 21, "kiarachobanova@abv.bg");
        CHECK_EQ(21, author.getAge());
    }

    TEST_CASE("Email getter"){
        Author author("kiara", "chobanova", 21, "kiarachobanova@abv.bg");
        CHECK_EQ("kiarachobanova@abv.bg", author.getEmail());
    }
}

TEST_SUITE("Book tests"){
    
    TEST_CASE("Name getter"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);

        CHECK_EQ(book.getName(), name);
    }

    TEST_CASE("Price getter"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);

        CHECK_EQ(book.getPrice(), price);
    }

    TEST_CASE("Text getter"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);

        CHECK_EQ(book.getText(), text);
    }

    TEST_CASE("Price setter"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);

        const double newPrice = 21;
        book.setPrice(newPrice);

        CHECK_EQ(book.getPrice(), newPrice);
    }

    TEST_CASE("Has author function"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);

        CHECK_FALSE(!book.hasAuthor("Ana", "Huang"));
    }
}

TEST_SUITE("Library tests"){
    TEST_CASE("operator[] test"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);
        Pair pair1;
        pair1.book = book;
        pair1.count = 1;
        Pair pairs[1] = {pair1};
        Library library(pairs, 1);

        CHECK_EQ(library["Twisted Love"], 1);
    }

    TEST_CASE("has book in library"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);
        Pair pair1;
        pair1.book = book;
        pair1.count = 1;
        Pair pairs[1] = {pair1};
        Library library(pairs, 1);

        CHECK_FALSE(!library.hasBookInLibrary(book));
    }

    TEST_CASE("take book"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);
        Pair pair1;
        pair1.book = book;
        pair1.count = 1;
        Pair pairs[1] = {pair1};
        Library library(pairs, 1);

        library.takeBook(book);
        CHECK_FALSE(library.hasBookInLibrary(book));
    }

    TEST_CASE("all books with author"){
        Author author1("Ana", "Huang", 27, "AnaHuang@abv.gr");
        Author authors[1] = { author1 };
        const string name = "Twisted Love";
        const size_t numberOfAuthors = 1;
        const double price = 20;
        const string text = "He has a heart of ice...but for her, he'd burn the world...";

        Book book(name, authors, numberOfAuthors, price, text);
        Pair pair1;
        pair1.book = book;
        pair1.count = 1;
        Pair pairs[1] = {pair1};
        Library library(pairs, 1);

        Book* resultBooks = library.allBooksWithAuthor(author1);
        for(int i = 0; i < 1; ++i){
            CHECK_FALSE(!(resultBooks[i] == pairs[i].book));
        }
        
        delete[] resultBooks;
    }

}