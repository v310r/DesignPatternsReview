//      The Strategy design pattern allows you to define a skeleton of an algorithm 
//  and then use composition to supply the missing implementation details 
//  related to a particular strategy. This approach exists in two incarnations:
//          • Dynamic strategy simply keeps a pointer/reference to 
//            the strategy being used. Want to change to a different 
//            strategy? Just change the reference. Easy!
//          • Static strategy requires that you choose the strategy at 
//            compile time and stick with it – there is no scope for 
//            changing your mind later on.
//      Should one use dynamic or static strategies? Well, dynamic 
//  ones allow you reconfiguration of the objects after they have been 
//  constructed. Imagine a UI setting that controls the form of the textual 
//  output: what would you rather have, a switchable TextProcessor
//  or two variables of type TextProcessor<MarkdownStrategy> and 
//  TextProcessor<HtmlStrategy>? It’s really up to you.
//      On a final note, you can constrain the set of strategies a type takes: 
//  instead of allowing a general ListStrategy argument, one can take an 
//  std::variant that lists the only permitted types that can be passed in.


#include <iostream>

#include "DynamicStrategy.hpp"
#include "StaticStrategy.hpp"


int main()
{
    // dynamic stratefy
    TextProcessor tp;
    tp.SetOutputFormat(OutputFormat::Markdown);
    tp.AppendList({ "foo", "bar", "baz" });
    std::cout << tp.Str() << std::endl;

    tp.Clear(); // clears the buffer
    tp.SetOutputFormat(OutputFormat::Html);
    tp.AppendList({ "foo", "bar", "baz" });
    std::cout << tp.Str() << std::endl;

    //static stratefy
    TextProcessor2<MarkdownListStrategy> tpm;
    tpm.AppendList({ "foo", "bar", "baz" });
    std::cout << tpm.Str() << std::endl;

    TextProcessor2<HtmlListStrategy> tph;
    tph.AppendList({ "foo", "bar", "baz" });
    std::cout << tph.Str() << std::endl;
}

