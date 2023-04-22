# NetflixRepo2
Run "g++ -std=c++11 main.cpp -o main -lcurl" to build 
the executable, and then either run "./main" or run 
the program in Clion or other C++ IDEs. 

Things done
1. Get all repositories from all pages.

2. Get bottom N view of repositories based on the following
   fields and order by their names alphabetically when there are ties.
1) Number of forks
2) Number of stars
3) Number of open issues
4) Last updated time

3. Get the list of members

Things TODO
1. Make it a service
This requires installing CppRestSDK, which then requires Xcode version > 12.4, 
and OS version > 11, which then requires >20GB storage space that my laptop can not afford.

2. Make the following endpoints
1) /view/bottom/N/forks
2) /view/bottom/N/last_updated
3) /view/bottom/N/open_issues
4) /view/bottom/N/stars

3. The service should read a GITHUB_API_TOKEN environment variable to overcome API
rate-limit restrictions.
   
4. The service should implement a /healthcheck endpoint that returns HTTP 200 when the
   service is ready to serve API responses.

5. The service should accept a port parameter on startup, so that we can customize how it
   runs.

6. Run tests

7. Cache the following endpoints periodically
1) /orgs/Netflix/members
2) /orgs/Netflix/repos

