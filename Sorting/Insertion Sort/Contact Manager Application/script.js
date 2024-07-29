document.getElementById('addContactButton').addEventListener('click', addContact);
document.getElementById('sortButton').addEventListener('click', sortContacts);

let contacts = [];

function addContact() {
    const nameInput = document.getElementById('nameInput').value;
    const phoneInput = document.getElementById('phoneInput').value;
    const emailInput = document.getElementById('emailInput').value;

    if (nameInput && phoneInput && emailInput) {
        contacts.push({ name: nameInput, phone: phoneInput, email: emailInput });
        displayContacts();
    }
}

function insertionSort(arr, key) {
    for (let i = 1; i < arr.length; i++) {
        let temp = arr[i];
        let j = i - 1;

        while (j >= 0 && arr[j][key].toLowerCase() > temp[key].toLowerCase()) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

function sortContacts() {
    const criteria = document.getElementById('sortCriteria').value;
    insertionSort(contacts, criteria);
    displayContacts();
}

function displayContacts() {
    const contactList = document.getElementById('contactList');
    contactList.innerHTML = '';

    contacts.forEach(contact => {
        const listItem = document.createElement('li');
        listItem.classList.add('contact-item');
        listItem.innerHTML = `<strong>Name:</strong> ${contact.name}<br>
                              <strong>Phone:</strong> ${contact.phone}<br>
                              <strong>Email:</strong> ${contact.email}`;
        contactList.appendChild(listItem);
    });
}
