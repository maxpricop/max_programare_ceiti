CREATE TABLE customers (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(150) NOT NULL UNIQUE,
    phone VARCHAR(30),
    password_hash VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE addresses (
    id SERIAL PRIMARY KEY,
    customer_id BIGINT UNSIGNED NOT NULL,
    address_line1 VARCHAR(255) NOT NULL,
    address_line2 VARCHAR(255),
    city VARCHAR(100) NOT NULL,
    postal_code VARCHAR(20) NOT NULL,
    country VARCHAR(100) NOT NULL,
    
    CONSTRAINT fk_addresses_customer
        FOREIGN KEY (customer_id)
        REFERENCES customers(id)
        ON DELETE CASCADE
);

CREATE TABLE categories (
    id SERIAL PRIMARY KEY,
    parent_category_id BIGINT UNSIGNED,
    name VARCHAR(100) NOT NULL,
    description TEXT,
    
    CONSTRAINT fk_categories_parent
        FOREIGN KEY (parent_category_id)
        REFERENCES categories(id)
        ON DELETE SET NULL
);

CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    category_id BIGINT UNSIGNED NOT NULL,
    sku VARCHAR(50) NOT NULL UNIQUE,
    brand VARCHAR(100),
    name VARCHAR(255) NOT NULL,
    description TEXT,
    price DECIMAL(10,2) NOT NULL,
    gender ENUM('men', 'women', 'unisex'),
    stock_quantity INT NOT NULL DEFAULT 0,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    
    CONSTRAINT fk_products_category
        FOREIGN KEY (category_id)
        REFERENCES categories(id)
        ON DELETE RESTRICT
);

CREATE TABLE orders (
    id SERIAL PRIMARY KEY,
    customer_id BIGINT UNSIGNED NOT NULL,
    date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    status ENUM('pending','paid','shipped','cancelled') NOT NULL DEFAULT 'pending',
    total_amount DECIMAL(10,2) NOT NULL,
    shipping_cost DECIMAL(10,2) DEFAULT 0,
    address_line1 VARCHAR(255) NOT NULL,
    address_line2 VARCHAR(255),
    city VARCHAR(100) NOT NULL,
    postal_code VARCHAR(20) NOT NULL,
    country VARCHAR(100) NOT NULL,
    
    CONSTRAINT fk_orders_customer
        FOREIGN KEY (customer_id)
        REFERENCES customers(id)
        ON DELETE CASCADE
);

CREATE TABLE order_items (
    id SERIAL PRIMARY KEY,
    order_id BIGINT UNSIGNED NOT NULL,
    product_id BIGINT UNSIGNED NOT NULL,
    quantity INT NOT NULL,
    unit_price DECIMAL(10,2) NOT NULL,
    size VARCHAR(10),
    color VARCHAR(50),
    
    CONSTRAINT fk_order_items_order
        FOREIGN KEY (order_id)
        REFERENCES orders(id)
        ON DELETE CASCADE,
        
    CONSTRAINT fk_order_items_product
        FOREIGN KEY (product_id)
        REFERENCES products(id)
        ON DELETE RESTRICT
);

CREATE TABLE payments (
    id SERIAL PRIMARY KEY,
    order_id BIGINT UNSIGNED NOT NULL UNIQUE,
    payment_method VARCHAR(50) NOT NULL,
    amount DECIMAL(10,2) NOT NULL,
    status ENUM('pending','confirmed','failed','refunded') NOT NULL,
    paid_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    transaction_reference VARCHAR(150),
    
    CONSTRAINT fk_payments_order
        FOREIGN KEY (order_id)
        REFERENCES orders(id)
        ON DELETE CASCADE
);

CREATE TABLE reviews (
    id SERIAL PRIMARY KEY,
    customer_id BIGINT UNSIGNED NOT NULL,
    product_id BIGINT UNSIGNED NOT NULL,
    rating INT NOT NULL CHECK (rating BETWEEN 1 AND 5),
    title VARCHAR(150),
    description TEXT,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    
    CONSTRAINT fk_reviews_customer
        FOREIGN KEY (customer_id)
        REFERENCES customers(id)
        ON DELETE CASCADE,

    CONSTRAINT fk_reviews_product
        FOREIGN KEY (product_id)
        REFERENCES products(id)
        ON DELETE CASCADE
);

-- INSERTS for customers (15 rows)
INSERT INTO customers (name, email, phone, password_hash) VALUES
('Alex Popescu',    'alex.popescu@example.com',    '+40 722 000001', 'hash_alex'),
('Maria Ionescu',   'maria.ionescu@example.com',   '+40 722 000002', 'hash_maria'),
('Ion Vasilescu',   'ion.vasilescu@example.com',   '+40 722 000003', 'hash_ion'),
('Elena Stan',      'elena.stan@example.com',      '+40 722 000004', 'hash_elena'),
('Mihai Radulescu', 'mihai.radulescu@example.com', '+40 722 000005', 'hash_mihai'),
('Ana Georgescu',   'ana.georgescu@example.com',   '+40 722 000006', 'hash_ana'),
('Andrei Petrescu', 'andrei.petrescu@example.com', '+40 722 000007', 'hash_andrei'),
('Ioana Dumitru',   'ioana.dumitru@example.com',   '+40 722 000008', 'hash_ioana'),
('Radu Matei',      'radu.matei@example.com',      '+40 722 000009', 'hash_radu'),
('Claudia Iliescu', 'claudia.iliescu@example.com', '+40 722 000010', 'hash_claudia'),
('Bogdan Marin',    'bogdan.marin@example.com',    '+40 722 000011', 'hash_bogdan'),
('Laura Florescu',  'laura.florescu@example.com',  '+40 722 000012', 'hash_laura'),
('Sorin Toma',      'sorin.toma@example.com',      '+40 722 000013', 'hash_sorin'),
('Cristina Filip',  'cristina.filip@example.com',  '+40 722 000014', 'hash_cristina'),
('Daniel Rusu',     'daniel.rusu@example.com',     '+40 722 000015', 'hash_daniel');

-- INSERTS for addresses (15 rows) - one per customer
INSERT INTO addresses (customer_id, address_line1, address_line2, city, postal_code, country) VALUES
(1,  'Strada Libertatii 10',     'Ap. 2',  'Bucharest',      '010101', 'Romania'),
(2,  'Bd. Eroilor 45',           NULL,      'Cluj-Napoca',    '400200', 'Romania'),
(3,  'Str. Victoriei 3',         'Bl. B, Sc. 1', 'Timisoara', '300300', 'Romania'),
(4,  'Str. Mare 22',             NULL,      'Iasi',           '700400', 'Romania'),
(5,  'Calea Constanta 78',       NULL,      'Constanta',      '900500', 'Romania'),
(6,  'Piata Unirii 5',           'Et. 1',   'Bucharest',      '020202', 'Romania'),
(7,  'Str. Primaverii 12',       NULL,      'Brasov',         '500600', 'Romania'),
(8,  'Str. Independentei 18',    'Ap. 7',  'Sibiu',          '550700', 'Romania'),
(9,  'Str. Noua 33',             NULL,      'Oradea',         '410800', 'Romania'),
(10, 'B-dul Republicii 2',       NULL,      'Craiova',        '200900', 'Romania'),
(11, 'Str. Mare 90',             'Casa',   'Ploiesti',       '100100', 'Romania'),
(12, 'Str. Pictorilor 7',        NULL,      'Buzau',          '120120', 'Romania'),
(13, 'Str. Salcamilor 4',        NULL,      'Galati',         '800800', 'Romania'),
(14, 'Str. Castanilor 11',       'Ap. 4',  'Targu Mures',    '540540', 'Romania'),
(15, 'Str. Libertatii 99',       NULL,      'Suceava',        '720720', 'Romania');

-- INSERTS for categories (15 rows)
-- parent_category_id references earlier rows where appropriate
INSERT INTO categories (parent_category_id, name, description) VALUES
(NULL,     'Men',           'Men clothing'),
(NULL,     'Women',         'Women clothing'),
(NULL,     'Kids',          'Kids clothing'),
(1,     'Shirts',        'Shirts for men'),
(1,     'Pants',         'Pants for men'),
(2,     'Dresses',       'Dresses for women'),
(2,     'Skirts',        'Skirts for women'),
(NULL,     'Outerwear',     'Jackets, coats, etc.'),
(NULL,     'Accessories',   'Hats, belts, scarves'),
(1,     'Shoes',         'Men shoes'),
(2,     'Swimwear',      'Swimsuits and trunks'),
(NULL,     'Activewear',    'Sports and gym wear'),
(1,     'Formal',        'Formal clothing for men'),
(NULL,     'Loungewear',    'Comfortable home wear');

-- INSERTS for products (20 rows) - each references an existing category id
INSERT INTO products (category_id, sku, brand, name, description, price, gender, stock_quantity) VALUES
(4,  'SKU-M-001',  'Zara',    'Classic Oxford Shirt',      'Cotton oxford shirt',                79.99,  'men',    50),
(5,  'SKU-M-002',  'Levi''s', 'Slim Fit Jeans',            'Denim slim fit jeans',               129.50, 'men',    40),
(6,  'SKU-W-001',  'H&M',     'Summer Floral Dress',       'Light summer dress',                 59.90,  'women',  30),
(7,  'SKU-W-002',  'Mango',   'Pleated Skirt',             'Midi pleated skirt',                 69.00,  'women',  25),
(8,  'SKU-O-001',  'Uniqlo',  'Puffer Jacket',             'Warm puffer jacket',                 149.00, 'unisex', 20),
(9,  'SKU-A-001',  'Fossil',  'Leather Belt',              'Genuine leather belt',               39.99,  'unisex', 100),
(10, 'SKU-S-001',  'Nike',    'Running Sneakers',          'Lightweight running shoes',          119.00, 'men',    60),
(11, 'SKU-SW-001', 'Arena',   'Women''s One-Piece',        'Chlorine resistant swimsuit',        45.00,  'women',  35),
(12, 'SKU-AW-001', 'Adidas',  'Training Hoodie',           'Breathable training hoodie',         89.50,  'unisex', 45),
(13, 'SKU-F-001',  'Tommy',   'Men''s Blazer',             'Slim formal blazer',                 199.99, 'men',    15),
(14, 'SKU-LW-001', 'Puma',    'Lounge Pants',              'Soft lounge pants',                  49.90,  'unisex', 70),
(4,  'SKU-M-003',  'Calvin',  'Casual Button Shirt',       'Everyday casual shirt',              69.00,  'men',    35),
(5,  'SKU-M-004',  'Wrangler','Regular Jeans',            'Comfort denim jeans',                99.00,  'men',    40),
(8,  'SKU-O-002',  'Columbia','Rain Shell',               'Waterproof shell jacket',            129.00, 'unisex', 22),
(6,  'SKU-W-003',  'Zara',    'Evening Gown',              'Elegant evening gown',               249.00, 'women',  10),
(9,  'SKU-A-002',  'Ray-Ban', 'Aviator Sunglasses',        'Classic metal aviator sunglasses',   129.99, 'unisex', 25),
(10, 'SKU-S-002',  'Adidas',  'Court Sneakers',            'Everyday court-style sneakers',      89.99,  'unisex', 80),
(12, 'SKU-AW-002', 'UnderArmour','Compression Tee',        'Quick-dry compression t-shirt',      39.99,  'unisex', 120),
(14, 'SKU-LW-002', 'H&M',     'Cotton Hoodie',             'Soft cotton hoodie',                 35.00,  'unisex', 150),
(5,  'SKU-M-005',  'Dockers', 'Smart Chino',               'Versatile slim chino pants',         79.00,  'men',    60);

-- INSERTS for orders (15 rows) - each references a customer and includes static address snapshot
-- total_amount roughly equals item price * quantity + shipping_cost
INSERT INTO orders (customer_id, date, status, total_amount, shipping_cost, address_line1, address_line2, city, postal_code, country) VALUES
(1,  '2024-01-05 10:15:00', 'paid',    79.99,  5.00, 'Strada Libertatii 10',    'Ap. 2',    'Bucharest',   '010101', 'Romania'),
(2,  '2024-01-06 11:20:00', 'paid',    134.50, 5.00, 'Bd. Eroilor 45',          NULL,       'Cluj-Napoca', '400200', 'Romania'),
(3,  '2024-01-07 09:05:00', 'shipped', 64.90,  5.00, 'Str. Victoriei 3',        'Bl. B, Sc. 1', 'Timisoara','300300', 'Romania'),
(4,  '2024-01-08 14:30:00', 'paid',    74.90,  5.00, 'Str. Mare 22',            NULL,       'Iasi',        '700400', 'Romania'),
(5,  '2024-01-09 12:00:00', 'pending', 154.00, 5.00, 'Calea Constanta 78',      NULL,       'Constanta',   '900500', 'Romania'),
(6,  '2024-01-10 16:45:00', 'paid',    119.00, 5.00, 'Piata Unirii 5',          'Et. 1',    'Bucharest',   '020202', 'Romania'),
(7,  '2024-01-11 08:10:00', 'shipped', 45.00,  5.00, 'Str. Primaverii 12',      NULL,       'Brasov',      '500600', 'Romania'),
(8,  '2024-01-12 19:50:00', 'paid',    89.50,  5.00, 'Str. Independentei 18',   'Ap. 7',    'Sibiu',       '550700', 'Romania'),
(9,  '2024-01-13 13:25:00', 'cancelled',124.90,5.00, 'Str. Noua 33',            NULL,       'Oradea',      '410800', 'Romania'),
(10, '2024-01-14 15:40:00', 'paid',    199.99, 5.00, 'B-dul Republicii 2',      NULL,       'Craiova',     '200900', 'Romania'),
(11, '2024-01-15 09:00:00', 'paid',    49.90,  5.00, 'Str. Mare 90',            'Casa',     'Ploiesti',    '100100', 'Romania'),
(12, '2024-01-16 10:10:00', 'paid',    69.00,  5.00, 'Str. Pictorilor 7',       NULL,       'Buzau',       '120120', 'Romania'),
(13, '2024-01-17 17:35:00', 'paid',    129.00, 5.00, 'Str. Salcamilor 4',       NULL,       'Galati',      '800800', 'Romania'),
(14, '2024-01-18 18:00:00', 'pending', 249.00, 10.00,'Str. Castanilor 11',      'Ap. 4',    'Targu Mures', '540540', 'Romania'),
(15, '2024-01-19 20:20:00', 'paid',    119.00, 5.00, 'Str. Libertatii 99',      NULL,       'Suceava',     '720720', 'Romania'),
(3,  '2024-01-20 09:15:00', 'paid',     109.00, 5.00,  'Str. Lalelelor 12',    NULL,       'Arad',        '310101', 'Romania'),
(7,  '2024-01-21 11:45:00', 'shipped',  89.99,  5.00,  'Str. Mihai Viteazu 8','Ap. 3',     'Brasov',      '500500', 'Romania'),
(12, '2024-01-22 14:10:00', 'paid',     59.99,  5.00,  'Str. Dorobanti 21',   NULL,       'Buzau',       '120200', 'Romania'),
(1,  '2024-01-23 16:25:00', 'pending',  179.00, 10.00, 'Str. Aviatorilor 44', NULL,       'Bucharest',   '011111', 'Romania'),
(9,  '2024-01-24 18:40:00', 'paid',     99.90,  5.00,  'Str. Closca 17',      NULL,       'Oradea',      '410410', 'Romania');

-- INSERTS for order_items (15 rows) - one item per order (you can add more if you want multiple items per order)
-- unit_price should correspond to product price in products table
INSERT INTO order_items (order_id, product_id, quantity, unit_price, size, color) VALUES
(1,  1, 1,  79.99,  'M',   'White'),
(2,  2, 1,  129.50, '32',  'Blue'),
(3,  3, 1,  59.90,  'S',   'Floral'),
(4,  4, 1,  69.00,  'M',   'Black'),
(5,  5, 1,  149.00, 'L',   'Navy'),
(6,  7, 1,  119.00, '42',  'Black'),
(7,  8, 1,  45.00,  'M',   'Blue'),
(8,  9, 1,  89.50,  'L',   'Grey'),
(9,  11,1,  119.00, '41',  'Black'),
(10, 10,1, 199.99,  '44',  'Navy'),
(11, 15,1, 49.90,   'M',   'Grey'),
(12, 12,1, 69.00,   'M',   'Black'),
(13, 14,1, 129.00,  'L',   'Olive'),
(14, 3, 1, 249.00,  'M',   'Red'),
(15, 6, 1, 39.99,   'M',   'Brown'),
(16, 13, 1, 104.00, 'L',  'Black'),
(17, 8,  2, 42.50,  'M',  'Blue'),
(18, 6,  1, 54.99,  'M',  'Brown'),
(19, 5,  1, 169.00, 'L',  'Grey'),
(20, 9,  1, 94.90,  'XL', 'Black');

-- INSERTS for payments (15 rows) - one payment per order (order_id is UNIQUE)
INSERT INTO payments (order_id, payment_method, amount, status, paid_at, transaction_reference) VALUES
(1,  'card', '84.99',  'confirmed', '2024-01-05 10:17:00', 'TXN-0001'),
(2,  'card', '139.50', 'confirmed', '2024-01-06 11:22:00', 'TXN-0002'),
(3,  'paypal','64.90',  'confirmed', '2024-01-07 09:07:00', 'TXN-0003'),
(4,  'card', '79.90',  'confirmed', '2024-01-08 14:31:00', 'TXN-0004'),
(5,  'card', '159.00', 'pending',   NULL,                'TXN-0005'),
(6,  'card', '124.00', 'confirmed', '2024-01-10 16:47:00', 'TXN-0006'),
(7,  'paypal','50.00',  'confirmed', '2024-01-11 08:12:00', 'TXN-0007'),
(8,  'card', '94.50',  'confirmed', '2024-01-12 19:52:00', 'TXN-0008'),
(9,  'card', '129.90', 'failed',     NULL,                'TXN-0009'),
(10, 'card', '204.99', 'confirmed', '2024-01-14 15:45:00', 'TXN-0010'),
(11, 'card', '54.90',  'confirmed', '2024-01-15 09:02:00', 'TXN-0011'),
(12, 'card', '74.00',  'confirmed', '2024-01-16 10:12:00', 'TXN-0012'),
(13, 'card', '134.00', 'confirmed', '2024-01-17 17:36:00', 'TXN-0013'),
(14, 'card', '259.00', 'pending',   NULL,                'TXN-0014'),
(15, 'card', '124.00', 'confirmed', '2024-01-19 20:22:00', 'TXN-0015'),
(16, 'card',   '114.00', 'confirmed', '2024-01-20 09:17:00', 'TXN-0016'),
(17, 'paypal', '94.99',  'confirmed', '2024-01-21 11:47:00', 'TXN-0017'),
(18, 'card',   '64.99',  'confirmed', '2024-01-22 14:12:00', 'TXN-0018'),
(19, 'card',   '189.00', 'pending',   NULL,                  'TXN-0019'),
(20, 'card',   '104.90', 'confirmed', '2024-01-24 18:42:00', 'TXN-0020');

-- INSERTS for reviews (15 rows)
INSERT INTO reviews (customer_id, product_id, rating, title, description, created_at) VALUES
(1,  1, 5, 'Great shirt',          'Very comfortable and well made.', '2024-01-20 09:00:00'),
(2,  2, 4, 'Good jeans',           'Fits well, looks good.', '2024-01-21 10:00:00'),
(3,  3, 5, 'Lovely dress',         'Perfect for summer.', '2024-01-22 11:00:00'),
(4,  4, 4, 'Nice skirt',           'Good quality fabric.', '2024-01-23 12:00:00'),
(5,  5, 5, 'Warm jacket',          'Keeps me warm in winter.', '2024-01-24 13:00:00'),
(6,  7, 4, 'Comfortable shoes',    'Good for running.', '2024-01-25 14:00:00'),
(7,  8, 3, 'Okay swimsuit',        'Decent but sizing runs small.', '2024-01-26 15:00:00'),
(8,  9, 5, 'Great hoodie',         'Very breathable and soft.', '2024-01-27 16:00:00'),
(9,  11,5, 'Excellent sneakers',   'Very light and comfortable.', '2024-01-28 17:00:00'),
(10, 10,4, 'Sharp blazer',         'Looks great for formal events.', '2024-01-29 18:00:00'),
(11, 15,4, 'Comfy pants',          'Perfect for home wear.', '2024-01-30 19:00:00'),
(12, 12,5, 'Nice swimsuit',        'Fits perfectly.', '2024-01-31 20:00:00'),
(13, 14,4, 'Good rain shell',      'Lightweight and waterproof.', '2024-02-01 09:30:00'),
(14, 3, 5, 'Stunning gown',        'Beautiful quality and cut.', '2024-02-02 10:30:00'),
(15, 6, 4, 'Nice belt',            'Leather feels solid.', '2024-02-03 11:30:00'),
(3,  13, 5, 'Fantastic quality',   'Exceeded my expectations.', '2024-02-04 09:00:00'),
(7,  8,  4, 'Nice fit',            'Very comfortable material.', '2024-02-05 10:00:00'),
(12, 6,  4, 'Good value',          'Worth the price.', '2024-02-06 11:00:00'),
(1,  5,  5, 'Excellent jacket',    'Perfect for cold weather.', '2024-02-07 12:00:00'),
(9,  9,  3, 'Average hoodie',      'Good but expected thicker fabric.', '2024-02-08 13:00:00');

-- 1) Schimbarea structurii: adaug o coloană și elimin o coloană existentă
ALTER TABLE reviews
    ADD COLUMN verified_purchase BOOLEAN NOT NULL DEFAULT 0 AFTER rating,
    DROP COLUMN title;

-- 2) Schimb tipul de date al coloanei rating: INT -> TINYINT UNSIGNED
ALTER TABLE reviews
    MODIFY COLUMN rating TINYINT UNSIGNED NOT NULL;

-- (opțional) Re-adaug un CHECK numit pentru rating (1..5).
-- Dacă serverul tău MariaDB refuză constrângerea, poți comenta / elimina această linie.
ALTER TABLE reviews
    ADD CONSTRAINT chk_reviews_rating CHECK (rating BETWEEN 1 AND 5);

-- 3) Creez constrângerea UNIQUE pe (customer_id, product_id) — o singură recenzie per client/produs
ALTER TABLE reviews
    ADD CONSTRAINT uq_reviews_customer_product UNIQUE (customer_id, product_id);

-- 4) Insertez încă 2 rânduri la final (aleg perechi customer/product care nu sunt duplicate)
INSERT INTO reviews (customer_id, product_id, rating, description, created_at, verified_purchase) VALUES
    (2, 5, 4, 'Good product, fits well.', '2024-02-10 10:00:00', 1),
    (4, 11, 5, 'Excellent quality and fast shipping.', '2024-02-11 12:00:00', 1);

-- 5) Șterg 3 rânduri de la începutul tabelului (primele 3 id-uri existente)
DELETE FROM reviews
    ORDER BY id ASC
    LIMIT 3;

-- 6) Modific (UPDATE) un rând: actualizez recenzia proaspăt inserată pentru (customer_id=2, product_id=5)
UPDATE reviews
SET rating = 5,
    description = 'Updated: now 5 stars after second use.',
    verified_purchase = 1,
    created_at = '2024-02-12 09:00:00'
WHERE customer_id = 2 AND product_id = 5;