def seconds_to_hours():
    total_seconds = int(input("input the total seconds: "))
    
    units = [
        {"name": "year", "value": 31536000},
        {"name": "month", "value": 2629800},
        {"name": "week", "value": 604800},
        {"name": "day", "value": 86400},
        {"name": "hour", "value": 3600},
        {"name": "minute", "value": 60},
        {"name": "second", "value": 1}
    ]
    
    result = []
    
    for unit in units:
        amount = total_seconds // unit["value"]
        total_seconds %= unit["value"]
        result.append({"name": unit["name"], "amount": amount})
        
    for i, res in enumerate(result): # 'i' is the iterator, 'res' is the value 
        if res["amount"] > 0:
            print(f"{res['amount']} {res['name']}(s)")
        
seconds_to_hours()
        