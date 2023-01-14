/* The Dependency Inversion principle states that our classes should depend upon interfaces or abstract classes instead of concrete classes and functions. */


class Logger {

       NtfsFileSystem _fileSystem = new NtfsFileSystem ();
 
       public void Log (string text) {
           fileStream = _fileSystem.OpenFile ("log.txt");
 
           fileStream.Write (text);
 
         }
   }
   
   /* Everything looks good, right? We have our Logger class that’s able to log a text message into a specific file of the file system. But we have some issues here. Our Logger class depends on the specific implementation of the NtfsFileSystem class. What if that class needs to change because of a new Ntfs version or because of a bug that has been fixed? It’s likely that our class will need to change, too! What if we need to log into another completely different type of file system? Or into a database? We realize that our code is tightly copuled and manteinance is difficult. */
   
   /*We declare an abstraction (interface) like this:*/

	class ILoggable
    {
        void Log(string textToLog);
    }
    
    class NtfsFileSystem : ILoggable {
       public void Log (string textToLog) {
           //file handling, writing and disposing.
       }
   }
   
   class Logger2 {
       private ILoggable _logService;
 
       public Logger (ILoggable logService) {
           if (logService == null) throw new ArgumentNullException ();
 
           _logService = logService;
       }
 
       public void Log (string text) {
           _logService.Log (text);
       }
   }
   
   
  /* What we’ve done here is to inject into the constructor the log sub-system we want to use. Our Logger2 class can work with every class that implements ILoggable. This is also very useful for unit testing purpose when we would like to remove externale dependencies and test our code in isolation (but that’s outside the scope of this post).
Our code is now loosely-coupled because the Logger2 class doesn’t depend on a specific implementation but only on an interface.*/

/* Now we can write a program like this, for example: */



class Program () {
        void Main () {
 
            var ntfsLogger = new Logger2 (new NtfsFileSystem ());
 
            var noSqlLogger = new Logger2 (new DbNoSql ());
 
            ntfsLogger.Log("some text");
 
            noSqlLogger.Log("other text");
        }

