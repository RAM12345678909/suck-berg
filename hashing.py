from docx import Document

def detect_hash_type(hash_value):
    """Detect the hash type based on its length."""
    hash_length = len(hash_value)
    if hash_length == 32:
        return 'MD5'
    elif hash_length == 40:
        return 'SHA1'
    elif hash_length == 64:
        return 'SHA256'
    else:
        return 'Unknown'

def search_hash_in_table(docx_file, hash_value, hash_type):
    """Search for the hash in the .docx file and return the corresponding password."""
    document = Document(docx_file)
    hash_column_index = {
        'MD5': 2, 
        'SHA1': 3,
        'SHA256': 4
    }.get(hash_type, None)

    if hash_column_index is None:
        return None

    for table in document.tables:
        for row in table.rows[1:]:  # Skip the header row
            if row.cells[hash_column_index].text.strip() == hash_value:
                return row.cells[1].text  # Password column
    return None

def main():
    # Ask the user to enter the hash
    user_hash = input("Enter the hash (MD5, SHA1, or SHA256): ").strip()
    hash_type = detect_hash_type(user_hash)

    if hash_type == 'Unknown':
        print("The hash type is unrecognized.")
    else:
        print(f"Detected hash type: {hash_type}")

        # Specify the path to your .docx file containing the rainbow table
        docx_file = r"C:\Users\Sara\Desktop\saraaaa"
        
        # Search for the hash and retrieve the password
        password = search_hash_in_table(docx_file, user_hash, hash_type)

        if password:
            print(f"Password found: {password}")
        else:
            print("Password not found.")

if __name__ == "__main__":
    main()
