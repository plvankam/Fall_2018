#include<iostream>
#include"main.h"


class MessageSender
{
	private:
	    MessageConverter* mMsgConverterPtr;

	public:
	    MessageSender() : mMsgConverterPtr(NULL) {}

	    void sendMessage(std::string msg)
	    {
	    	if(mMsgConverterPtr)
	    	{
	    		msg = mMsgConverterPtr->convert(msg);
	    	}
	    	std::cout << "Message Sent :: " << msg << std::endl;
	    }
	    void setMsgConverterPtr(MessageConverter* msgConverterPtr)
	    {
	    	mMsgConverterPtr = msgConverterPtr;
	    }
};

class NewMessageConverter : public MessageConverter
{
	public:
		std::string convert(std::string msg)
		{
			msg = "<START>" + msg + "<END>";
			return msg;
		}
};

std::string MessageConverter::convert(std::string msg)
		{
			msg = "[START]" + msg + "[END]";
			return msg;
		}


int main()
{

	MessageSender msgSenderObj;

	MessageConverter* msgConverterPtr = new MessageConverter();
	msgSenderObj.setMsgConverterPtr(msgConverterPtr);

	msgSenderObj.sendMessage("Hello World");
	delete msgConverterPtr;

	MessageConverter* newMsgConverterPtr = new NewMessageConverter();
	msgSenderObj.setMsgConverterPtr(newMsgConverterPtr);

	msgSenderObj.sendMessage("Hello World");
	delete msgConverterPtr;

	return 0;
}
