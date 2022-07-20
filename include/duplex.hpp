#pragma once

// duplex by reference
template <typename _Ty>
class dupRef
{
	_Ty& __a;
	_Ty& __b;
	bool& __rev;
public:
	dupRef() = delete;
	explicit dupRef(_Ty& _act, _Ty& _old, bool& _swap) : __a{ _act }, __b{ _old }, __rev{ _swap } {}
	_Ty& act() { return __rev ? __b : __a; }
	_Ty& old() { return __rev ? __a : __b; }
	void update() { old() = act(); }
};

// duplex container
template <typename _Ty>
class duplex : public dupRef<_Ty>
{
	_Ty a;
	_Ty b;
public:
	duplex() = delete;
	duplex(bool& _rev)
		: dupRef<_Ty>{ a, b, _rev }, a{}, b{} {}
	duplex(const _Ty& _a, const _Ty& _b, bool& _rev)
		: dupRef<_Ty>{ a, b, _rev }, a{ _a }, b{ _b } {}
	duplex(_Ty&& _a, _Ty&& _b, bool& _rev)
		: dupRef<_Ty>{ a, b, _rev }, a{ std::move(_a) }, b{ std::move(_b) } {}
};
