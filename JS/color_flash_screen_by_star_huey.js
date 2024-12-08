Javascript: (function() {
    const getRandomColor = () => {
        const letters = '0123456789ABCDEF';
        let color = '#';
        for (let i = 0; i < 6; i++) {
            color += letters[Math.floor(Math.random() * 16)];
        }
        return color;
    };
    let cooldown = 0;
    const step = () => {
        cooldown--;
        if (cooldown > 0) {
            window.requestAnimationFrame(step);
            return;
        }
        document.querySelectorAll('*').forEach(e => {
            let col = getRandomColor();
            e.style.background = col;
            e.style.setProperty('--darkreader-inline-bgcolor', col);
        });
        cooldown = 8;
        window.requestAnimationFrame(step);
    };
    const style = document.createElement('style');
    style.innerHTML = '*{transition:250ms ease;}';
    document.head.appendChild(style);
    step();
})()