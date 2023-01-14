/* The Single Responsibility Principle states that a class should do one thing and therefore it should have only a single reason to change.*/

#include <iostream>

class Book {
	String name;
	String authorName;
	int year;
	int price;
	String isbn;

	public :
	Book(String name, String authorName, int year, int price, String isbn) {
		this.name = name;
		this.authorName = authorName;
		this.year = year;
        this.price = price;
		this.isbn = isbn;
	}
};

class Invoice {

	public : 
	
	Invoice(Book book, int quantity, double discountRate, double taxRate) {
		this.book = book;
		this.quantity = quantity;
		this.discountRate = discountRate;
		this.taxRate = taxRate;
		this.total = this.calculateTotal();
	}

	public double calculateTotal() {
	        double price = ((book.price - book.price * discountRate) * this.quantity);

		double priceWithTaxes = price * (1 + taxRate);

		return priceWithTaxes;
	}

	public void printInvoice() {
            //priting the invoice in predefined-format 
	}

        public void saveToFile(String filename) {
	// Creates a file with given name and writes the invoice
	}
	
	private : 
	Book book;
	int quantity;
	double discountRate;
	double taxRate;
	double total;
};

/*

Our class violates the Single Responsibility Principle in multiple ways.

The first violation is the printInvoice method, which contains our printing logic. The SRP states that our class should only have a single reason to change, and that reason should be a change in the invoice calculation for our class.

But in this architecture, if we wanted to change the printing format, we would need to change the class. This is why we should not have printing logic mixed with business logic in the same class.

There is another method that violates the SRP in our class: the saveToFile method. It is also an extremely common mistake to mix persistence logic with business logic.

Don't just think in terms of writing to a file – it could be saving to a database, making an API call, or other stuff related to persistence.

So how can we fix this print function, you may ask.

We can create new classes for our printing and persistence logic so we will no longer need to modify the invoice class for those purposes.

We create 2 classes, InvoicePrinter and InvoicePersistence, and move the methods.

*/


class InvoicePrinter {
    
    public InvoicePrinter(Invoice invoice) {
        this.invoice = invoice;
    }

    public void print() {
        //priting the invoice in some format
    }
    private:
    Invoice invoice;
}

public class InvoicePersistence {


    public InvoicePersistence(Invoice invoice) {
        this.invoice = invoice;
    }

    public void saveToFile(String filename) {
        // Creates a file with given name and writes the invoice
    }
    
    private:
    Invoice invoice;
}
