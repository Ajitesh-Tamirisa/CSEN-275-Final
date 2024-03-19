#include <iostream>
#include <vector>
#include <algorithm>

// LineFilter interface
class LineFilter {
public:
    virtual bool shouldNotify(const std::string& line) = 0;
};

// Concrete LineFilters
class KeywordFilter : public LineFilter {
private:
    std::string keyword;
public:
    KeywordFilter(const std::string& keyword) : keyword(keyword) {}
    bool shouldNotify(const std::string& line) {
        std::string lowerLine = line;
        std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);
        return lowerLine.find(keyword) != std::string::npos;
    }
};

class LengthFilter : public LineFilter {
private:
    int length;
public:
    LengthFilter(int length) : length(length) {}
    bool shouldNotify(const std::string& line) {
        return line.length() > length;
    }
};

// Observer interface
class Observer {
protected:
    LineFilter* filter;
public:
    Observer(LineFilter* filter) : filter(filter) {}
    virtual void notify(const std::string& line) = 0;
};

// Concrete Observers
class KeywordObserver : public Observer {
public:
    KeywordObserver(LineFilter* filter) : Observer(filter) {}
    void notify(const std::string& line) {
        if (filter->shouldNotify(line)) {
            std::cout << "Yes! " << line << std::endl;
        }
    }
};

class LengthObserver : public Observer {
public:
    LengthObserver(LineFilter* filter) : Observer(filter) {}
    void notify(const std::string& line) {
        if (filter->shouldNotify(line)) {
            std::cout << "So long....! " << line << std::endl;
        }
    }
};

// Text analysis app
class TextAnalysisApp {
private:
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }
    void processLine(const std::string& line) {
        for (Observer* observer : observers) {
            observer->notify(line);
        }
    }
};

int main() {
    TextAnalysisApp app;

    // Register observers with their respective filters
    app.registerObserver(new KeywordObserver(new KeywordFilter("interesting")));
    app.registerObserver(new LengthObserver(new LengthFilter(60)));

    // Assume that these lines are being read from a file
    app.processLine("This is an interesting line of text.");
    app.processLine("Let us say that this line of text is not very interesting, but it is quite long and exceeds the given character limit.");

    return 0;
}
