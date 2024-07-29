document.addEventListener('DOMContentLoaded', () => {
    const gridElement = document.getElementById('grid');
    const startBtn = document.getElementById('startBtn');
    const nums = [2, 3, 1, 1, 4, 2, 1, 5, 1, 1]; // Example array
    const rows = 1;
    const cols = nums.length;
    let grid = [];

    // Initialize grid
    function createGrid() {
        gridElement.innerHTML = '';
        grid = [];
        for (let col = 0; col < cols; col++) {
            const cell = document.createElement('div');
            cell.classList.add('cell');
            cell.textContent = nums[col];
            gridElement.appendChild(cell);
            grid.push(cell);
        }
    }

    // Jump Game Algorithm Visualization
    function jumpGame(nums) {
        let pos = 0;
        let des = 0;
        let jump = 0;
        const n = nums.length;
        for (let i = 0; i < n - 1; i++) {
            des = Math.max(des, nums[i] + i);
            grid[i].classList.add('visited');
            if (pos === i) {
                pos = des;
                jump++;
                grid[i].classList.add('jump');
                if (pos >= n - 1) break;
            }else {
                
            }
        }
        alert(`Minimum stops: ${jump}`);
    }

    // Event Listener
    startBtn.addEventListener('click', () => {
        createGrid();
        setTimeout(() => jumpGame(nums), 500); // Delay for visualization
    });

    // Initial grid creation
    createGrid();
});
