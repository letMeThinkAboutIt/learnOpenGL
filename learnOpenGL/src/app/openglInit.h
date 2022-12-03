#pragma once

class openglInit {
public:
	virtual bool initOpengl() = 0;
	virtual void run() = 0;
	virtual ~openglInit() {}
};