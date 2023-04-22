#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <curl/curl.h>

using namespace std;

struct NetflixRepo {
    string name;
    int forks;
    int stars;
    int open_issues;
    string last_update;
    public:
    NetflixRepo(string n, int f, int s, int oi, string lu) :
               name(n), forks(f), stars(s), open_issues(oi), last_update(lu) {}
};

struct cmpForks {
    public:
    bool operator() (NetflixRepo r1, NetflixRepo r2) {
        if (r1.forks == r2.forks) {
            return r1.name > r2.name;
        }
        return r1.forks < r2.forks;
    }
};

struct cmpOpenIssues {
    public:
    bool operator() (NetflixRepo r1, NetflixRepo r2) {
        if (r1.open_issues == r2.open_issues) {
            return r1.name > r2.name;
        }
        return r1.open_issues < r2.open_issues;
    }

};

struct cmpStars {
public:
    bool operator() (NetflixRepo r1, NetflixRepo r2) {
        if (r1.stars == r2.stars) {
            return r1.name > r2.name;
        }
        return r1.stars < r2.stars;
    }
};

struct cmpLastUpdate {
public:
    bool operator() (NetflixRepo r1, NetflixRepo r2) {
        if (r1.last_update == r2.last_update) {
            return r1.name > r2.name;
        }
        return r1.last_update < r2.last_update;
    }
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

vector<pair<string, int> > getBottomNForks(vector<NetflixRepo> repos, int n) {
    vector<pair<string, int> > res;
    // max heap
    priority_queue<NetflixRepo, vector<NetflixRepo>, cmpForks> pq;
    for (NetflixRepo repo : repos) {
        pq.push(repo);
        if (pq.size() > n) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        NetflixRepo repo = pq.top();
        pq.pop();
       // cout << "repo name: " << repo.name << ", forks: " << repo.forks << endl;
        res.push_back({repo.name, repo.forks});
    }

    return res;
}

vector<pair<string, int> > getBottomNOpenIssues(vector<NetflixRepo> repos, int n) {
    vector<pair<string, int> > res;
    // max heap
    priority_queue<NetflixRepo, vector<NetflixRepo>, cmpOpenIssues> pq;
    for (NetflixRepo repo : repos) {
        pq.push(repo);
        if (pq.size() > n) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        NetflixRepo repo = pq.top();
        pq.pop();
        cout << "repo name: " << repo.name << ", open issues: " << repo.open_issues << endl;
        res.push_back({repo.name, repo.open_issues});
    }

    return res;
}

vector<pair<string, int> > getBottomNStars(vector<NetflixRepo> repos, int n) {
    vector<pair<string, int> > res;
    // max heap
    priority_queue<NetflixRepo, vector<NetflixRepo>, cmpStars> pq;
    for (NetflixRepo repo : repos) {
        pq.push(repo);
        if (pq.size() > n) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        NetflixRepo repo = pq.top();
        pq.pop();
        cout << "repo name: " << repo.name << ", stars: " << repo.stars << endl;
        res.push_back({repo.name, repo.stars});
    }

    return res;
}

vector<pair<string, string> > getBottomNLastUpdates(vector<NetflixRepo> repos, int n) {
    vector<pair<string, string> > res;
    // max heap
    priority_queue<NetflixRepo, vector<NetflixRepo>, cmpLastUpdate> pq;
    for (NetflixRepo repo : repos) {
        pq.push(repo);
        if (pq.size() > n) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        NetflixRepo repo = pq.top();
        pq.pop();
        cout << "repo name: " << repo.name << ", last update: " << repo.last_update << endl;
        res.push_back({repo.name, repo.last_update});
    }

    return res;
}

set<string> getPeople(string buffer) {
    set<string> res;
    string mark = "alt=\"@";
    int index = buffer.find(mark);
    while (index >= 0) {
        buffer = buffer.substr(index + mark.length());
        index = buffer.find("\"");
        string member = buffer.substr(0, index);
        //cout << "member: " << member << endl;
        if (member != "Netflix") {
            res.insert(member);
        }
        buffer = buffer.substr(index + 1);
        index = buffer.find(mark);
    }
    return res;
}

string getBufferFromUrl(const char* url) {
    CURL *curl;
    CURLcode res;
    string readBuffer = "";
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

void getRepos(vector<NetflixRepo>& repos, string repo_buffer) {
    string name_mark = "class=\"d-inline-block\"";
    string fork_mark = "aria-label=\"fork\"";
    string svg_mark = "</svg>";
    string end_mark = "</";
    string datetime_mark = "datetime=\"";
    string allowed_chars = "-._";
    int index = repo_buffer.find(name_mark);
    while (index >= 0) {
        // get name
        repo_buffer = repo_buffer.substr(index + name_mark.length());
        int end = repo_buffer.find(end_mark);
        string s = repo_buffer.substr(0, end);
        string name;
        for (char c : s) {
            if (isalnum(c) || allowed_chars.find(c) != string::npos) {
                name.append(1, c);
            }
        }
        cout << "name: " << name << endl;
        // get forks
        index = repo_buffer.find(fork_mark);
        repo_buffer = repo_buffer.substr(index + fork_mark.length());
        int begin = repo_buffer.find(svg_mark);
        repo_buffer = repo_buffer.substr(begin + svg_mark.length());
        end = repo_buffer.find(end_mark);
        s = repo_buffer.substr(0, end);
        string ss;
        for (char c : s) {
            if (isdigit(c)) {
                ss.append(1, c);
            }
        }
        cout << "fork: " << ss << endl;
        int forks = stoi(ss);
        //cout << "fork: " << forks << endl;
        // get stars
        begin = repo_buffer.find(svg_mark);
        repo_buffer = repo_buffer.substr(begin + svg_mark.length());
        end = repo_buffer.find(end_mark);
        s = repo_buffer.substr(0, end);
        ss.clear();
        for (char c : s) {
            if (isdigit(c)) {
                ss.append(1, c);
            }
        }
        int stars = stoi(ss);
        cout << "star: " << stars << endl;
        // open issue
        begin = repo_buffer.find(svg_mark);
        repo_buffer = repo_buffer.substr(begin + svg_mark.length());
        end = repo_buffer.find(end_mark);
        s = repo_buffer.substr(0, end);
        ss.clear();
        for (char c : s) {
            if (isdigit(c)) {
                ss.append(1, c);
            }
        }
        int open_issues = stoi(ss);
        cout << "open issue: " << open_issues << endl;
        // last update
        begin = repo_buffer.find(datetime_mark);
        repo_buffer = repo_buffer.substr(begin + datetime_mark.length());
        end = repo_buffer.find("\"");
        string last_update = repo_buffer.substr(0, end);
        cout << "last update: " << last_update << endl;
        repos.push_back(NetflixRepo(name, forks, stars, open_issues, last_update));
        index = repo_buffer.find(name_mark);
    }

}

set<string> getPaginationUrlSuffixes(string repo_buffer) {
    set<string> res;
    string pagination_mark = "pagination";
    string pagination_url_mark = "href=\"";
    int index = repo_buffer.find(pagination_mark);
    repo_buffer = repo_buffer.substr(index + 1);
    string end_mark = "</div>";
    int end = repo_buffer.find(end_mark);
    repo_buffer = repo_buffer.substr(0, end);
    index = repo_buffer.find(pagination_url_mark);
    while (index >= 0) {
        repo_buffer = repo_buffer.substr(index + pagination_url_mark.length());
        end = repo_buffer.find("\"");
        string pagination_url = repo_buffer.substr(0, end);
        //cout << "pagination url: " << pagination_url << endl;
        res.insert(pagination_url);
        index = repo_buffer.find(pagination_url_mark);
    }
    return res;
}

int main(void)
{
    string github_url = "https://github.com";
  string people_endpoint  = "/orgs/Netflix/people";
  string repo_endpoint = "/orgs/Netflix/repositories";
  string people_buffer = getBufferFromUrl((github_url + people_endpoint).c_str());
  string repo_buffer = getBufferFromUrl((github_url + repo_endpoint).c_str());
  cout << repo_buffer << endl;

  getPeople(people_buffer);
    vector<NetflixRepo> repos;
    getRepos(repos, repo_buffer);
  set<string> pagination_url_suffixes = getPaginationUrlSuffixes(repo_buffer);
  for (string suffix : pagination_url_suffixes) {
      repo_buffer = getBufferFromUrl((github_url + suffix).c_str());
      //cout << repo_buffer << endl;
      getRepos(repos, repo_buffer);
  }
  int n = 7;
  getBottomNForks(repos, n);
    getBottomNOpenIssues(repos, n);
    getBottomNStars(repos, n);
    getBottomNLastUpdates(repos, n);
  return 0;
}
