document.getElementById('sortButton').addEventListener('click', insertionSort);

function insertionSort() {
    const inputArray = document.getElementById('inputArray').value.split(',').map(Number);
    const visualizationContainer = document.getElementById('visualization');
    visualizationContainer.innerHTML = '';

    inputArray.forEach((value, index) => {
        const bar = document.createElement('div');
        bar.style.height = `${value * 5}px`;
        bar.classList.add('bar');
        visualizationContainer.appendChild(bar);
    });

    let i = 1;
    const interval = setInterval(() => {
        if (i < inputArray.length) {
            let key = inputArray[i];
            let j = i - 1;

            while (j >= 0 && inputArray[j] > key) {
                inputArray[j + 1] = inputArray[j];
                j = j - 1;
            }
            inputArray[j + 1] = key;

            updateVisualization(inputArray);
            i++;
        } else {
            clearInterval(interval);
        }
    }, 1000);
}

function updateVisualization(array) {
    const bars = document.getElementsByClassName('bar');
    array.forEach((value, index) => {
        bars[index].style.height = `${value * 5}px`;
    });
}
