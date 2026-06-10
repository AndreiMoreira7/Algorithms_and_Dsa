const secondsToYears = () => {
    let totalSeconds = Number(prompt("input the seconds: "))
    
    if(isNaN(totalSeconds)){
        alert("please input a valid number")
        return
    }
    
    const units = [
        {name: 'year', value: 31536000},
        {name: 'month', value: 2629800},
        {name: 'week', value: 604800},
        {name: 'day', value: 86400},
        {name: 'hour', value: 3600},
        {name: 'minute', value: 60},
        {name: 'second', value: 1}
    ];

    const result = units.reduce((acc, unit) => {
        const count = Math.floor(totalSeconds / unit.value)
        totalSeconds %= unit.value
        acc.push(`${count} ${unit.name}(s)`)
        return acc
    }, [])
    
    alert(`[${result.join(': ')}]`)
}

secondsToYears()