/* The Open-Closed Principle requires that classes should be open for extension and closed to modification */

public class InvoicePersistence {


    public InvoicePersistence(Invoice invoice) {
        this.invoice = invoice;
    }

    public void saveToFile(String filename) {
        // Creates a file with given name and writes the invoice
    }
    
    public void saveToDataBase(String filename) {
        // Creates a file with given name and writes the invoice
    }
    
    private:
    Invoice invoice;
}

/* Continuing the single resposibility principle example where we have createtd seperate class InvoicePersistence but that class is not extensible for new saving functionality we need to add seperate functions like saveToFile, saveToDataBase to exiting classs which will violate open closed principle so we have restructred the InvoicePersitance class in a below way to adhere to open close principle*/

class InvoicePersistence {

    virtaul void save(Invoice invoice) = 0;
}

class DatabasePersistence : public InvoicePersistence {

    void save(Invoice invoice) {
        // Save to DB
    }
}

class FilePersistence : public InvoicePersistence {

    void save(Invoice invoice) {
        // Save to file
    }
}
