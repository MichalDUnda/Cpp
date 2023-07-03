#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
using namespace std;

// dynamic strategy

enum class OutputFormat
{
    Markdown,
    Html
};

struct ListStrategy
{
    virtual ~ListStrategy() = default;
    virtual void add_list_item(ostringstream& oss, const string& item){};
    virtual void start(ostringstream& oss){};
    virtual void end(ostringstream& oss){};
};

struct MarkdownListStrategy : ListStrategy
{
    void add_list_item(ostringstream& oss, const string& item) override
    {
        oss << " * " << item << endl;
    }
};

struct HtmlListStrategy : ListStrategy
{
    void start(ostringstream& oss) override
    {
        oss << "<ul>" << endl;
    }

    void end(ostringstream& oss) override
    {
        oss << "</ul>" << endl;
    }

    void add_list_item(ostringstream& oss, const string& item) override
    {
        oss << "<li>" << item << "</li>" << endl;
    }
};

struct TextProcessor
{
    void clear()
    {
        oss.str("");
        oss.clear();
    }
    void append_list(const vector<string> items)
    {
        list_strategy->start(oss);
        for(auto& item : items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }

    void set_output_format(const OutputFormat format)
    {
        switch(format)
        {
            case OutputFormat::Markdown:
                list_strategy = make_unique<MarkdownListStrategy>();
                break;
            case OutputFormat::Html:
                list_strategy = make_unique<HtmlListStrategy>();
                break;
            default:
                throw runtime_error("Unsupported strategy.");
        }
    }
    string str() const
    {
        return oss.str();
    }

private:
    std::ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};

template <typename ST>
struct TextProcessorStatic
{
    void clear()
    {
        oss.str("");
        oss.clear();
    }
    void append_list(const vector<string> items)
    {
        list_strategy.start(oss);
        for(auto& item : items)
            list_strategy.add_list_item(oss, item);
        list_strategy.end(oss);
    }

    string str() const
    {
        return oss.str();
    }

private:
    std::ostringstream oss;
    ST list_strategy;
};

void dynamicStrategyMain()
{
    TextProcessor tp;
    tp.set_output_format(OutputFormat::Markdown);
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str() << endl;

    // html
    tp.clear();
    tp.set_output_format(OutputFormat::Html);
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str() << endl;
}

void staticStrategyMain()
{
    TextProcessorStatic<MarkdownListStrategy> tp;
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str() << endl;

    // html
    TextProcessorStatic<HtmlListStrategy> tp2;
    tp2.append_list({"foo", "bar", "baz"});
    cout << tp2.str() << endl;
}

int main()
{
    dynamicStrategyMain();

    getchar();

    staticStrategyMain();
    getchar();
    return 0;
}
